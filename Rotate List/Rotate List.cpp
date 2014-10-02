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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0) return head;
        ListNode *fast = head;
        ListNode *node = head;
        int count = 1;
        while (node->next != NULL) {
            ++count;
            node = node->next;
        }
        node->next = head;
        node = head;
        k = k % count;
        for (int i = 0; i <= k; ++i) fast = fast->next;
        
        while (fast != head) {
            fast = fast->next;
            node = node->next;
        }
        ListNode *newHead = node->next;
        node->next = NULL;
        return newHead;
        
    }
};