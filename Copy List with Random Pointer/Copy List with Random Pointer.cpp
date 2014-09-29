/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *dummyNode = new RandomListNode(0);
        RandomListNode *dummyNewHead = new RandomListNode(0);
        RandomListNode *dummyNewNode = dummyNewHead;
        dummyNode->next = head;
        unordered_map<RandomListNode *, RandomListNode *> map;
        while (dummyNode->next != NULL) {
            {
                auto it = map.find(dummyNode->next);
                if (it == map.end()) {
                    dummyNewNode->next = new RandomListNode(dummyNode->next->label);
                } else dummyNewNode->next = it->second;
            }
            {
                if (dummyNode->next->random != NULL) {
                    auto it = map.find(dummyNode->next->random);
                    if (it == map.end()) {
                        dummyNewNode->next->random = new RandomListNode(dummyNode->next->random->label);
                    } else dummyNewNode->next->random = it->second;
                }
            }
            dummyNewNode = dummyNewNode->next;
            dummyNode = dummyNode->next;
        }
        return dummyNewHead->next;
    }
};