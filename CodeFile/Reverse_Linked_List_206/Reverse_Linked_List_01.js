
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}


var reverseList = function(head) {

    let previous = null;
    let current = head;
    console.log(current);
    while(current != null){
        let nextNode = current.next;
        current.next = previous;
        previous = current;
        current = nextNode;
    }

    console.log(previous);
    return previous;

};


/*

    1. Understanding double pointer in the linked list.
    --> pointer and variable difference should be separate.
 */
