//Node
class Node{
    constructor(data, next){
        this.data = data;
        this.next = next;
    }
}

var MyLinkedList = function() {
    this.head = null;
    this.size = 0;
};

/**
 * @param {number} index
 * @return {number}
 */
MyLinkedList.prototype.get = function(index) {
    //out of the range
    if(index < 0 || index >= this.size){
        console.log("Out of the range.");
        return -1
    }
    let cur = this.head;
    let pre;
    let count = 0;
    while(count < index){
        count ++;
        pre = cur;
        cur = cur.next;
    }
    console.log(cur.data);
    return cur.data;
};

/**
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function(val) {
    this.head = new Node(val, this.head);
    this.size ++;
};

/**
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtTail = function(val) {
    let node = new Node(val);
    let current;

    //if empty, make head
    if(!this.head){

        this.head = node;

    }else{
        current = this.head;
        while(current.next){
            current = current.next;
        }
        current.next = node;
    }
    this.size ++;
};

/**
 * @param {number} index
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtIndex = function(index, val) {
    if(index > 0 && index > this.size){
        console.log("Out of the range");
        return;
    }

    if(index === 0){
        this.addAtHead(val);
        this.size ++;
        return;
    }

    if(index === this.size){
        let node = new Node(val);
        let current;

        current = this.head;
        while(current.next){
            current = current.next;
        }
        current.next = node;
        this.size ++;
        return;
    }

    let pre;
    let cur = this.head;
    let count = 0;
    while(count < index){
        count ++;
        pre = cur;
        cur = cur.next;
    }
    let data = new Node(val);
    pre.next = data;
    data.next = cur;

    this.size ++;
    return;
};

/**
 * @param {number} index
 * @return {void}
 */
MyLinkedList.prototype.deleteAtIndex = function(index) {

        //index >= size Out of the range
        if(index < 0 ||index > 0 && index >= this.size){
            console.log("Out of the range");
            return -1;
        }


        //index === 0
        if(index === 0){
            this.head = this.head.next;
            this.size --;
            return;
        }

        let cur = this.head;
        let count = 0;
        let pre;

        //index > 0 && < size
        while(count < index){
            count ++;
            pre = cur;
            cur = cur.next;
        }
        pre.next = cur.next;
        this.size --;
};

MyLinkedList.prototype.printLinkedList = function(){
    let currentNode = this.head;
    while(currentNode){
        console.log(currentNode.data);
        currentNode = currentNode.next;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */

var obj = new MyLinkedList()


obj.addAtIndex(0,10);
obj.addAtIndex(0,20);

obj.printLinkedList();


/*
    [Results]:
    Runtime     114ms;       Beats 70.86% of users with JavaScript;
    Memory      50.58mb;    Beats 56.09% of users with JavaScript;
 */