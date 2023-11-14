//[3rd]: Recursive Method - PreOrder

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

//PreOrder - 順序：中、左、右 (利用 Class 概念去實踐)
var countNodes = function(root){

    //結果值
    let result = 0;

    //Step 2: 確認終止條件
    if(root === null) return result;

    //Step 1: 確認參數及回傳值型態，此返回值為  Int
    const getNodesNume = (root, depth) =>{

        //Step 3: 確定單層邏輯
        //中：
        result = result + depth;
        //左：
        if(root.left !== null){
            getNodesNume(root.left, depth);
        }
        //右:
        if(root.right !== null){
            getNodesNume(root.right, depth);
        }
    }

    getNodesNume(root, 1);
    console.log(result);
    return result;
}





let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);
root.right.left = new TreeNode(6);

console.log(root);

countNodes(root)