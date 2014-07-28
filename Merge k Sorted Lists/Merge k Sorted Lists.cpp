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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;
        else if (lists.size() == 1) return lists[0];
        
        vector<ListNode *> newLists;
        for (int i = 0; i < lists.size(); i+=2) {
            ListNode *l1 = lists[i];
            ListNode *l2 = nullptr;
            if (i + 1 < lists.size()) l2 = lists[i + 1];
            newLists.push_back(mergeTwoLists(l1, l2));
        }
        
        return mergeKLists(newLists);
    
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1) p->next = l1;
        else p->next = l2;
        return dummy->next;
    }
};