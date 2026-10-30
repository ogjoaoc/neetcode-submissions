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
    ListNode* reverseList(ListNode* head) {
        ListNode * answer_head = NULL;
        while (head != NULL) {
            ListNode * cur = new ListNode();
            cur->val = head->val;
            cur->next = NULL;
            if (answer_head == NULL) {
                answer_head = cur;
            } else {
                cur->next = answer_head;
                answer_head = cur;
            }
            head = head->next;
        }
        return answer_head;
    }
};
