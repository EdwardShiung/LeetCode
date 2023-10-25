//[3rd]:
//Iterative Method (Queue Method)

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}


var isSymmetric = function(root){

    if(root === null) return root;

    //利用 Queue
    let queue = new Array();
    queue.push(root.left);
    queue.push(root.right);

    while(queue.length){
        let leftNode = queue.shift();
        let rightNode = queue.shift();
        if(leftNode === null && rightNode === null) continue;
        if(leftNode === null || rightNode === null) return false;
        if(leftNode.val !== rightNode.val) return false

        queue.push(leftNode.left);
        queue.push(rightNode.right);
        queue.push(leftNode.right);
        queue.push(rightNode.left);
    }

    console.log(true);
    return true;

}


let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(2);
root.left.left = new TreeNode(3);
root.left.right = new TreeNode(4);
root.right.left = new TreeNode(4);
root.right.right = new TreeNode(3);


// console.log(root);

isSymmetric(root);