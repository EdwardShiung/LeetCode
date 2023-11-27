//[2nd]: Iterative Method

//ES5
function TreeNode(val,left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}


var binaryTreePaths = function(root){




}



let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.right = new TreeNode(5);