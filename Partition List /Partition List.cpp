/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *large = new ListNode(0);
        ListNode *lTail = large;
        ListNode *small = new ListNode(0);
        ListNode *sTail = small;
        while (head != NULL) {
            if (head->val < x) {
                sTail->next = head;
                sTail = sTail->next;
            }
            else {
                lTail->next = head;
                lTail = lTail->next;
            }
            head = head->next;
        }
        sTail->next = large->next;
        lTail->next = NULL;
        return small->next;
    }
};