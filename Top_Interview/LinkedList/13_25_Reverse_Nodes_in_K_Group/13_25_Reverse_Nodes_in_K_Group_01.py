class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = LisNode(0, head)
        groupPrev = dummy
        
        
        while True:
            kth = self.getKth(groupPrev, k)
            if not kth:
                break
            groupNext = kth.next
            prev = kth.next
            curr = groupPrev.next
            
            # Reverse Group
            while curr != groupNext:
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp
                
            # Update groupPrev & groupNext
            tmp = groupPrev.next
            groupPrev.next = kth
            groupPrev = tmp
            
        return dummy.next
    
    # Set a helper function
    def getKth(self, curr, k):
        while curr and k > 0:
            curr = curr.next
            k -= 0
        return curr