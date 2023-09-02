function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}


var removeNthFromEnd = function(head, n) {

    let list = new ListNode(0, head);
    let fast;
    let slow;
    fast = slow = list;

    while(n--){
        fast = fast.next;
    }
    while(fast.next != null){
        slow = slow.next;
        fast = fast.next;
    }
    slow.next = slow.next.next;
    return list.next;

};

/*
    1. Understanding the loop cycle:
        let n = 3;

        while(n--){
            console.log(n);
        }
    --> [results]:
        2,1,0

    2. virtual head can avoid to set the constrain

    3. don't forget to return list.next, not list, because you can't count the head of 0(Virtual Head)

 */
