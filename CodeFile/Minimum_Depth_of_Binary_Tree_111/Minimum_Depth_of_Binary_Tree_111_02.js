//[2nd]: Recursive Method - PostOrder


//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

//後序：左、右、中 (後序是利用高度去求深度)
var minDepth = function(root){

    console.log(getHeight(root));
    return getHeight(root);

}

const getHeight = (node) =>{

    //Base Case:
    if(node === null) return 0;

    //左
    let leftHeight = 0;
    if(node.left !== null) leftHeight = getHeight(node.left);
    //右
    let rightHeight = 0;
    if(node.right !== null) rightHeight = getHeight(node.right);

    //中：
    //計算 ：當左子樹不為空，右子樹為空，計算左子樹最低點：
    if(node.left !== null && node.right === null) {
        return 1 + leftHeight;
    }
    //計算 ：當左子樹為空，右子樹不為空，計算右子樹最低點：
    if(node.left === null && node.right !== null) {
        return 1 + rightHeight;
    }
    //計算 ：當左、右子樹皆不為空時，計算最小的值：
    result = 1 + Math.min(leftHeight, rightHeight);

    //返回結果：
    return result;
}



let root = new TreeNode(3);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);

// console.log(root);

minDepth(root)

/**
 * 此寫法當然可以更加精簡，但精簡後，對於思考幫助性較少。
 */

//[2nd]：此為超級精簡版本
// var minDepth = function(root) {
//     // Base Case: root === null
//     if (root === null) return 0;

//     // 使用遞迴計算左右子樹的最小深度
//     const leftDepth = minDepth(root.left);
//     const rightDepth = minDepth(root.right);

//     // 如果左子樹或右子樹為空，返回非空子樹的深度+1，否則返回最小深度+1
//     if (leftDepth === 0 || rightDepth === 0) {
//         return leftDepth + rightDepth + 1;
//     } else {
//         return Math.min(leftDepth, rightDepth) + 1;
//     }
// };
