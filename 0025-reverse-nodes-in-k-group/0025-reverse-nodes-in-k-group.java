class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
       
        ListNode cursor = head;
        int count = 0;
        while (cursor != null && count < k) {
            cursor = cursor.next;
            count++;
        }
         
        if (count < k) {
            return head;
        }
        
        ListNode prev = null;
        ListNode curr = head;
        ListNode nextNode = null;
        
        for (int i = 0; i < k; i++) {
            nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
    
        head.next = reverseKGroup(curr, k);
        
        return prev;
    }
}