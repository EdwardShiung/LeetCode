//[2nd]

//ES5
// function TreeNode (val, left, right){
//     this.val = val === undefined ? 0 : val;
//     this.left = left === undefined ? null : left;
//     this.right = right === undefined ? null : right;
// }

//ES6
class TreeNode{
    constructor(val, left, right){
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ? null : right;
    }
}


var postorderTraversal = function(root) {

    let result = [];
    if(root === null) return result;

    let stack = [root];
    let cur;

    while(stack.length){
        cur = stack.pop();
        if(cur.left) stack.push(cur.left);
        if(cur.right) stack.push(cur.right);
        result.push(cur.val);
    }

    result = result.reverse();
    console.log(result);
    return result;

}


let root = new TreeNode(1);
root.right = new TreeNode(2);
root.right.left = new TreeNode(3)

// console.log(root);
postorderTraversal(root);