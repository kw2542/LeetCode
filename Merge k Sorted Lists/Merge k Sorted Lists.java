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
    public ListNode mergeKLists(List<ListNode> lists) {
        if (lists == null || lists.isEmpty()) return null;
        else if (lists.size() == 1) return lists.get(0);
        
        List<ListNode> newLists = new ArrayList<ListNode>();
        for (int i = 0; i < lists.size(); i += 2) {
            ListNode l1 = lists.get(i);
            ListNode l2 = null;
            if (i + 1 < lists.size()) l2 = lists.get(i + 1);
            newLists.add(mergeTwoLists(l1, l2));
        }
        return mergeKLists(newLists);
    }
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode lastNode = dummy;
        
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                lastNode.next = l1;
                l1 = l1.next;
            } else {
                lastNode.next = l2;
                l2 = l2.next;
            }
            lastNode = lastNode.next;
        }
        
        if (l1 != null)  lastNode.next = l1;
        else  lastNode.next = l2;
        
        return dummy.next;
    }
}