//[1st]:
//Recursive Method

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

function comparedNode(left, right){

    // console.log(left)
    //determined the situation of which node is null.

    if(left === null && right === null) return true;
    if(left === null || right === null) return false;
    if(left.val !== right.val) return false;

    //Recursive Method Determine:
    let outside = comparedNode(left.left, right.right);
    let inside = comparedNode(left.right, right.left);

    console.log(outside && inside);
    return outside && inside;
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


/**
 * Complier not pass but leetcode website pass!!
 */