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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *root = new ListNode(0);
        ListNode *p = root;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int val = carry;
            if (l1 != NULL) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                val += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(val % 10);
            p = p->next;
            carry = val / 10;
        }
        if (carry == 1) p->next = new ListNode(1);
        return root->next;
    }
};