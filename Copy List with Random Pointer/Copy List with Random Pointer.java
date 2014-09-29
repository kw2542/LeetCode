/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        RandomListNode dummyNode = new RandomListNode(0);
        RandomListNode dummyNewHead = new RandomListNode(0);
        RandomListNode dummyNewNode = dummyNewHead;
        dummyNode.next = head;
        HashMap<RandomListNode, RandomListNode> map = new HashMap<>();
        while (dummyNode.next != null) {
            {
                RandomListNode it = map.get(dummyNode.next);
                if (it == null) {
                    dummyNewNode.next = new RandomListNode(dummyNode.next.label);
                } else dummyNewNode.next = it;
            }
            {
                if (dummyNode.next.random != null) {
                    RandomListNode it = map.get(dummyNode.next.random);
                    if (it == null) {
                        dummyNewNode.next.random = new RandomListNode(dummyNode.next.random.label);
                    } else dummyNewNode.next.random = it;
                }
            }
            dummyNewNode = dummyNewNode.next;
            dummyNode = dummyNode.next;
        }
        return dummyNewHead.next;
    }
}