//[1st]


//ES5
function Node(val, left, right, next){
    this.val = val === undefined ? null : val,
    this.left = left === undefined ? null : left,
    this.right = right === undefined ? null : right,
    this.next = next === undefined ? null : next;
}


var connect = function(root){

    if(root === null) return root;

    let queue = [root];

    while(queue.length){
        let size = queue.length;
        for(let i = 0; i < size; i++){
            let node = queue.shift();
            if(i < size - 1){
                node.next = queue[0];
            }

            if(node.left !== null) queue.push(node.left);
            if(node.right !== null) queue.push(node.right);
        }

    }

    console.log(root);
    return root;
}


let root = new Node(1);
root.left = new Node(2);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right = new Node(3);
root.right.right = new Node(7);

// console.log(root);

connect(root);
