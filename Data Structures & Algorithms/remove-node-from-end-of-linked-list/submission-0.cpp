/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * cur = head;
        int N = 0;
        while (cur != nullptr) {
            cur = cur->next;
            N++;
        }
        int k = N - n, i = 0;
        if (k == 0) return head->next;
        cout << "k = " << k << '\n';
        cur = head;
        ListNode * prev = nullptr;
        while (cur != nullptr && i < k) {
            prev = cur;
            cur = cur->next;
            i++;
        }
        cout << N << '\n';
        if (prev != nullptr) {
            if (cur != nullptr) {
                prev->next = cur->next;
            }
        }
        return head;
    }
};
