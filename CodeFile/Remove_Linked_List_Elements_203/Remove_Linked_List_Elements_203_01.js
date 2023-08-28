/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.



Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []
 */
//[1st Trial]


// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

var removeElements = function(head, val) {

    let list = new ListNode(0, head);
    let currentNode = list;

    console.log(list);
    console.log(currentNode);
    while(currentNode.next){
        if(currentNode.next.val === val){
            currentNode.next = currentNode.next.next ;
            continue;
        }else{
            currentNode = currentNode.next;
        }
    }
    return list.next;
};


/*
    1. I understand how to define a node:

        class Node{
            //constructor of node
            constructor(value, next){
                this.val = value;
                this.next = next || null;
            }
        }
 */

let head = [1,2,6,3,4,5,6];
let val = 6;
removeElements(head,val);
