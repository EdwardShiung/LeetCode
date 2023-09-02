function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}


var detectCycle = function(head) {
    let fast = head;
    let slow = head;

    while(fast != null && fast.next != null){
        fast = fast.next.next;
        slow = slow.next;

        if(fast === slow){
            let index_01 = fast;
            let index_02 = head;

            while(index_01 != index_02){
                index_01 = index_01.next;
                index_02 = index_02.next;
            }
            return index_01;
        }
    }
    return null;
};

/*

    1. I set the variable: x for entering the circle entrance; y for two pointer meet up; z for the rest of distance to entrance;
    2. fast pointer is 2 times move than slow pointer;
    3. Once 2 pointers meet up, we will know the X & Z distance, which could set another two pointers for the head and rest of distance.

 */