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
    return compared(root.left, root.right);

}

function compared(rootLeft, rootRight){

    //determined the situation of which node is null.

    //以下這個寫法，無法確定 rootLeft 或 rootRight 為 null
    // if(rootLeft === null && rootRight === null) return true;
    // if(rootLeft === null && rootRight !== null) return false;
    // if(rootLeft !== null && rootRight === null) return false;


    //改用這種寫法：
    if (rootLeft === null && rootRight === null) return true;
    if (rootLeft === null || rootRight === null) return false;
    if(rootLeft.val !== rootRight.val) return false;

    //after above situation, which value is the same
    //Recursive Method Determine:
    let outside = compared(rootLeft.left, rootRight.right);
    let inside = compared(rootLeft.right, rootRight.left);

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


compared(root);


/**
 * Complier not pass but leetcode website pass!!
 */