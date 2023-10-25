//[2nd]:
//Iterative Method (Stack Method)

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

var isSymmetric = function(root){

    if(root === null) return true;

    // 利用 stack 來存儲左右兩邊的節點
    let stack = new Array();
    // 進入循環前，先放入根節點中，左和右兩個節點
    stack.push(root.left);
    stack.push(root.right);

    while(stack.length){

        // 進入迴圈後，比較左右兩節點：
        let rightNode = stack.pop();
        let leftNode = stack.pop();

        if(leftNode === null && rightNode === null) continue;
        if(leftNode === null || rightNode === null) return false;
        if(leftNode.val !== rightNode.val ) return false;


        stack.push(leftNode.left);
        stack.push(rightNode.right);
        stack.push(leftNode.right);
        stack.push(rightNode.left);

    }

    console.log(true);
    return true;
}

// var isSymmetric = function(root) {
//     // 迭代方法判断是否是对称二叉树
//     // 首先判断root是否为空
//     if(root === null) {
//         return true;
//     }
//     let stack = [];
//     stack.push(root.left);
//     stack.push(root.right);
//     while(stack.length) {
//         let rightNode = stack.pop();    //左节点
//         let leftNode=stack.pop();       //右节点
//         if(leftNode === null && rightNode === null) continue;
//         if(leftNode === null || rightNode === null) return false;
//         if(leftNode.val !== rightNode.val ) return false;
//         if(leftNode.val !== rightNode.val) return false;

//         stack.push(leftNode.left);      //左节点左孩子入队
//         stack.push(rightNode.right);    //右节点右孩子入队
//         stack.push(leftNode.right);     //左节点右孩子入队
//         stack.push(rightNode.left);     //右节点左孩子入队
//     }
//     console.log(true);
//     return true;
// };

let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(2);
root.left.left = new TreeNode(3);
root.left.right = new TreeNode(4);
root.right.left = new TreeNode(4);
root.right.right = new TreeNode(3);


// console.log(root);

isSymmetric(root);
