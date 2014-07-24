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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        for (int i = 0; i < n; ++i) {
            if (q != nullptr) q = q->next;
            else break;
        }
        if (q == nullptr) return head->next; // remove head
        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        if (p->next != nullptr) p->next = p->next->next; // not remove the tail
        return head;
    }
};