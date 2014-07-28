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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 0 || k == 1 || head == nullptr) return head;
        int len = 0;
        ListNode *p = head;
        for (;p != nullptr; p = p->next) {
            ++len;
        }
        int multi = len / k;
        p = head;
        ListNode *preTail = nullptr;
        for (int i = 0; i < multi; ++i) {
            ListNode *preNode = nullptr;
            ListNode *nextNode = nullptr;
            ListNode *curTail = nullptr;
            for (int j = 0; j < k; ++j) {
                nextNode = p->next;
                p->next = preNode;
                preNode = p;
                if (j == 0) curTail = p;
                p = nextNode;
            }
            if (i == 0) {
                head->next = p;
                head = preNode;
            } 
            if (preTail != nullptr) preTail->next = preNode;
	            preTail = curTail;
            if (i == multi - 1) curTail->next = p;
        }
        return head;
    }
};