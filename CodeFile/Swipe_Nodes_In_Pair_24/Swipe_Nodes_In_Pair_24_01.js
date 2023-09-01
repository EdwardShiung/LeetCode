//[1st]:
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}


var swapPairs = function(head) {

    let dummyhead = new ListNode(0, head);
    let cur = dummyhead;

    while(cur.next != null && cur.next.next != null){
        let tmp = cur.next;
        let tmp_1 = cur.next.next.next;

        cur.next = cur.next.next;
        cur.next.next = tmp;
        cur.next.next.next = tmp_1;

        cur = cur.next.next

    }
    return dummyhead.next;

};



/*
    1. I did this question at the first time like that:

        if(!head || head.next === null) return;

        let next = head.next;
        let tmp;
        let pre = head;

        while(next != null){
            tmp = next.val;
            next = pre.val;
            pre = tmp;

            pre = next.next;
            next = pre.next;
        }

        return pre;

    --> I should set the limitation first.
*/