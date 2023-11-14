//[2nd]:Recursive Method - PostOrder

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

//PostOrder - 順序：左、右、中
var countNodes = function(root){

    return getNodesNume(root);

}

//Step 1: 確認參數和返回值類型，此返回值必定為 int
const getNodesNume = (root) => {
    //Step 2: 確認終止條件：
    if(root === null) return 0;

    //Step 3:確定單層邏輯
    let leftNodes = getNodesNume(root.left);
    let rightNodes = getNodesNume(root.right);
    let midNode = 1 + leftNodes + rightNodes;

    console.log(midNode);
    return midNode;

}


let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);
root.right.left = new TreeNode(6);

// console.log(root);

countNodes(root);