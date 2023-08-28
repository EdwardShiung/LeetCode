//Create the Node
class Node{
    constructor(val, next){
        this.val = val;
        this.next = next || null;
    }
}

//Create the LinkedList
class LinkedList {
    constructor(){
        this.head = null;
        this.size = 0;
    }

    //Insert First Node
    insertFirst(data){
        this.head = new Node(data, this.head);
        this.size ++;
    }
    //Insert Last Node
    insertLast(data){
        let node = new Node(data);
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
    }
    //Insert at Index
    insertAt(data, index){

        //out of the range
        if(index > 0 && index > this.size){
            console.log("Out of range");
            return;
        }
        //insert At the first index
        //[1st]: using the insertFirst function
        //[2nd]: re-code again
        if(index === 0){
            this.head = new Node(data, this.head);
            return;
        }

        // It could be improved!!!
        //insert at the among of the linked list
        if(index > 0 && index < this.size){
            let cur = this.head;
            let pre;
            let count = 0;
            // console.log(cur.next);
            while(count < index){
                pre = cur;
                count ++;
                cur = cur.next;
                if(count === index - 1){
                    let node = new Node(data);
                    pre.next = node;
                    node.next = cur;
                }
            }
        }
        this.size ++;
    }


    //Get at Index
    getIndex(index){

        let cur = this.head;
        // console.log(cur);

        if(index >= this.size){
            console.log("Out of the range");
            return;
        }

        let count = 0;
        let pre;
        while(count < index){
            pre = cur;
            count ++;
            cur = cur.next;
        }
        console.log("The data is " +cur.val);
    }
    //Remove at Index

    removeAt(index){

        //index >= size Out of the range
        if(index > 0 && index >= this.size){
            console.log("Out of the range");
            return;
        }

        let cur = this.head;
        let count = 0;
        let pre;

        //index === 0
        if(index === 0){
            this.head = cur.next;
        }

        //index > 0 && < size
        while(count < index){
            count ++;
            pre = cur;
            cur = cur.next;
        }
        pre.next = cur.next;
        this.size --;
        return;
    }

    //Clear List
    clearList(){
        this.head = null;
        this.size = 0;
        console.log("Clear All of the list!!");
    }

    //Print List
    printListData(){
        let currentNode = this.head;
        while(currentNode){
            console.log(currentNode.val);
            currentNode = currentNode.next;
        }
    }

}

let node = new LinkedList();

node.insertFirst(1);
node.insertFirst(2);
node.insertFirst(3);
node.insertLast(4);
node.insertLast(50);

node.insertAt(77,2);
node.insertAt(100,4);
// console.log(node);
node.printListData();
// console.log(node .size);
node.getIndex(6)
node.removeAt(3);
node.printListData();
node.clearList();
node.printListData();
// console.log(node.size);