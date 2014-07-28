/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (k == 0 || k == 1 || head == null) return head;
        int len = 0;
        ListNode p = head;
        for (;p != null; p = p.next) {
            ++len;
        }
        int multi = len / k;
        p = head;
        ListNode preTail = null;
        for (int i = 0; i < multi; ++i) {
            ListNode preNode = null;
            ListNode nextNode = null;
            ListNode curTail = null;
            for (int j = 0; j < k; ++j) {
                nextNode = p.next;
                p.next = preNode;
                preNode = p;
                if (j == 0) curTail = p;
                p = nextNode;
            }
            if (i == 0) {
                head.next = p;
                head = preNode;
            } 
            if (preTail != null) preTail.next = preNode;
	            preTail = curTail;
            if (i == multi - 1) curTail.next = p;
        }
        return head;
    }
}