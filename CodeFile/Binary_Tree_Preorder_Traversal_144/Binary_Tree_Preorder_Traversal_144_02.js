//[2nd]: Iterative Method


//ES5 Style
// function TreeNode(val, left, right){
//     this.val = (val === undefined ? 0 : val);
//     this.left = (left === undefined ? null : left);
//     this.right = (right === undefined ? null : right);
// }

//ES6 Style
class TreeNode{
    constructor(val, left, right){
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? 0 : left;
        this.right = right === undefined ? 0 : right;
    }
}

var preorderTraversal = function(root) {

    let result = [];

    if(root === null) return result;

    let stack = [root];
    //using a current pointer to point the node of stack.
    let cur;

    while(stack.length){
        cur = stack.pop();
        result.push(cur.val);
        //Be careful: we need to know if null, it will not continue.
        if(cur.right) stack.push(cur.right);
        if(cur.left) stack.push(cur.left);
    }
    console.log(result);
    return result;
}


//Each laryer we give them a new linked-list to be a new node.
let root = new TreeNode();
let second = new TreeNode();
let third = new TreeNode();
root.val = 1;
second.val = 2;
third.val = 3
second.left = third;

root.right = second;


// let root = [1, null, 2, 3]
preorderTraversal(root);

console.log(root);