//[1st]:
/*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values.
(i.e., from left to right, level by level from leaf to root).
*/

//ES5
function TreeNode (val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

var levelOrderBottom = function(root){

    let result = [];

    if(root === null) return result;

    let queue = [root];

    let cur = root;

    while(queue.length){
        // Understanding the size of each layer
        let size = queue.length;

        let temp = [];

        while(size --){
            cur = queue.shift();
            if(cur !== null) temp.push(cur.val);
            if(cur.left !== null) queue.push(cur.left);
            if(cur.right !== null) queue.push(cur.right);
        }
        result.push(temp);

    }

    result = result.reverse()

    console.log(result);
    return result;

}



let root = new TreeNode(3);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);


// console.log(root);
levelOrderBottom(root);