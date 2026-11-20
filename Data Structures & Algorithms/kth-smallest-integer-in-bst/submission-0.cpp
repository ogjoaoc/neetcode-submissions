/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, int> sz;
        auto dfs = [&](auto &dfs, TreeNode * cur) -> void {
            if (cur == nullptr) return;
            sz[cur] = 1;
            dfs(dfs, cur->left);
            sz[cur] += sz[cur->left];
            dfs(dfs, cur->right);
            sz[cur] += sz[cur->right];
        };
        dfs(dfs, root);
        TreeNode * cur = root;
        while (cur) {
            int left_size = sz[cur->left];
            if (k <= left_size) {
                cur = cur->left;
            } else if (k == left_size + 1) {
                return cur->val;
            } else {
                k -= (left_size + 1);
                cur = cur->right;
            }
        }
        return -1;
    }
};
