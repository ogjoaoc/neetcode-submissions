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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](auto && dfs, TreeNode * u) -> int {
            int hl = 0;
            int hr = 0;
            if (u->left != NULL) {
                hl = dfs(dfs, u->left);
            }
            if (u->right != NULL) {
                hr = dfs(dfs, u->right);
            }
            ans = max(ans, hl + hr);
            return 1 + max(hl, hr);
        };
        dfs(dfs, root);
        return ans;
    }
};
