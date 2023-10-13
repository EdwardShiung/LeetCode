//[2nd]

//ES5 Define a Node
// function TreeNode(val, left, right){
//     this.val = val === undefined ? 0 : val;
//     this.left = left === undefined ? null : left;
//     this.right = right === undefined ? null : right;
// }

//ES6
class TreeNode{
    constructor(val, left, right){
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ? null :right;
    }
}


var inorderTraversal = function(root){

    let result = [];

    if(root === null) return result;

    let stack = [];

    let cur = root;

    while(cur !== null || stack.length > 0){

        if(cur !== null){
            stack.push(cur);
            cur = cur.left;
        }else{

            cur = stack.pop();
            // console.log(cur)
            result.push(cur.val);
            cur = cur.right;
        }
    }

    console.log(result);
    return result;
}

//======== 如果是講解給自己聽或他人，傾向於第二種方式建立 ========//

//第一種用 Linked List 方式建立 Tree Node 節點：
// const root = new TreeNode(1);
// root.right = new TreeNode(2);
// root.right.left = new TreeNode(3);


//第二種用 Linked List 方式建立 Tree Node 節點：
let root = new TreeNode();
let second = new TreeNode();
let third = new TreeNode();

root.val = 1;
root.right = second;
root.left = null;
second.val = 2;
second.left = third;
second.right = null
third.val = 3;
third.left = null;
third.right = null;


// console.log(root);

inorderTraversal(root);