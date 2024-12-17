class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def partiiton(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        # left is smaller than x
        left = ListNode(0)
        # pointer for left
        currLeft = left

        # right is bigger than x
        right = ListNode(0)
        # pointer for right
        currRight = right

        # curr pointer
        curr = head

        while curr:
            if curr.val < x:
                currLeft.next = curr
                currLeft = currLeft.next
            else:
                currRight.next = curr
                currRight = currRight.next

            curr = curr.next

        currRight.next = None
        currLeft.next = right.next

        return left.next
        