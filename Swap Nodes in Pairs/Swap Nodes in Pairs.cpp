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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        while (p != NULL && p->next != NULL && p->next->next != NULL) {
            ListNode *t = p->next;
            p->next = t->next;
            t->next = t->next->next;
            p->next->next = t;
            p = t;
        }
        return dummy->next;
    }
};