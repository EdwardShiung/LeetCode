//[1st]: Iterative Method

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}


var isSymmetric = function(root){

    if(root === null) return true;

    console.log(root.left, root.right);
    return comparedNode(root.left, root.right);

}

function comparedNode(Left, Right){

    //determined the situation of which node is null.

    if(Left === null && Right === null) return true;
    if(Left === null && Right !== null) return false;
    if(Left !== null && Right === null) return false;
    if(Left.val !== Right.val) return false;

    //Recursive Method Determine:
    let outside = comparedNode(Left.left, Right.right);
    let inside = comparedNode(Left.right, Right.left);

    // console.log(true);
    return outside && inside;
}


let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(2);
root.left.left = new TreeNode(3);
root.left.right = new TreeNode(4);
root.right.left = new TreeNode(4);
root.right.right = new TreeNode(3);


comparedNode(root);
// console.log(root);


/**
 * Complier not pass but leetcode website pass!!
 */