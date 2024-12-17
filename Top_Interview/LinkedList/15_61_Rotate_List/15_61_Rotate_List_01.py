class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Edge Case_01: 空鏈表或不需要旋轉的情況
        if not head or not head.next or k == 0:
            return head
        
        # 1. 計算鏈表長度
        length = 1
        curr = head
        while curr.next:
            curr = curr.next
            length += 1
        
        # 2. 處理 k 大於 length
        k = k % length
        if k == 0:
            return head
        
        # 3. Rotate list 處理
        # 目前 curr 在 末端
        # 將末端接到 head
        curr.next = head

        # 4. 找到新的尾部 (length - k - 1)
        new_tail = head
        for _  in range(length - k - 1):
            new_tail = new_tail.next
        
        # 新的頭
        new_head = new_tail.next
        # 更新尾
        new_tail.next = None

        return new_head