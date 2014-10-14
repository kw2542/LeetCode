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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *node = dummy;
        dummy->next = head;
        while (node->next != NULL && node->next->next !=NULL) {
            if (node->next->val == node->next->next->val) {
                int val = node->next->val;
                ListNode *tmp = node;
                while (tmp->next != NULL && tmp->next->val == val) tmp = tmp->next;
                node->next = tmp->next;
            } else node = node->next;
        }
        return dummy->next;
    }
};