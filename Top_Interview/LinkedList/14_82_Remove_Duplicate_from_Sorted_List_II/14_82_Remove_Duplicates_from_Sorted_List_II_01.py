class ListNode:
    def __init__(self, val=0, next):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        prev, curr = dummy, head

        while curr != None and curr.next != None:
            # 判斷當前節點和下一個節點是否相同
            if curr.val == curr.next.val:
                # 跳過所有相同的節點
                duplicate_node = curr.val
                while curr and curr.val == duplicate_nodeq:
                    curr = curr.next
                
                # 將 prev 接入 非重複節點
                prev.next = curr
            else:
                prev = curr
                curr = curr.next
        
        return dummy.next