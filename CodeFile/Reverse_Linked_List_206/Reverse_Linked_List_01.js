
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}


var reverseList = function(head) {

    let previous = null;
    let current = head;

    while(current != null){
        //save the current next node to a temporary variable
        let nextNode = current.next;
        //change the direction
        current.next = previous;
        //move the pre & current pointer
        previous = current;
        current = nextNode;
    }

    return previous;

};


/*

    1. Understanding double pointer in the linked list.
    --> pointer and variable difference should be separate.
 */
