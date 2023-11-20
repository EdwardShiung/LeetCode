//[1st]: Recursvie Method - PostOrder

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

//利用 PostOrder - 左、右、中
var isBalanced = function(root){

    result = getHeight(root);

    if(result !== -1){
        console.log(true);
        return true;
    }else{
        console.log(false);
        return false;
    }



}


//Step 1: 建立參數和返回值型態，此返回值為 int
const getHeight = function(node){
    //Step 2: 建立終止條件
    //葉子節點時，返回 0
    if(node === null) return 0;

    //Step 3: 單層邏輯
    //左：(統計左子樹高度)
    let leftHeight = getHeight(node.left);
    //如果左子樹高度返回為 -1 ，則代表不為平衡二叉樹，直接往上再返回即可
    if(leftHeight === -1) return -1;

    //右：(統計右子樹高度)
    let rightHeight = getHeight(node.right);
    //如果右子樹高度返回為 -1 ，則代表不為平衡二叉樹，直接往上再返回即可
    if(rightHeight === -1) return -1;

    //中：(中間處理左、右高度)
    let result = 0;
    // 大於1，不符合平衡二叉樹
    if(Math.abs(leftHeight - rightHeight) > 1){
        return -1;
    }else{
        //若符合平和二叉樹，計算一下這棵樹的高度
        result = 1 + Math.max(leftHeight, rightHeight);
    }
    console.log(result);
    return result;

}

//Test Case_01
// let root = new TreeNode(3);
// root.left = new TreeNode(9);
// root.right = new TreeNode(20);
// root.right.left = new TreeNode(15);
// root.right.right = new TreeNode(7);

//Test Case_02
let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(2);
root.left.left = new TreeNode(3);
root.left.right = new TreeNode(3);
root.left.left.left = new TreeNode(4);
root.left.left.right = new TreeNode(4);

isBalanced(root);

/*
    1. 本題用後序方法來求解，原因：

        先行處理左右是否為平衡二叉樹後，中間可以總結左、右兩邊合併時，是否也為平和二叉樹
    --> 只要是可以利用中間總結，就可以使用後序

    2. 對於根節點是否深度為 1 取決於題目定義：
        - LeetCode 將根節點視為 1
            - LeetCode 都是以節點為 1 度，因此，根節點深度是 1
        - Wikipedia 將根節點視為 0
            - Wikipedia 都是用邊為 1 度，因此，根節點深度是 1

本題，請與 LeetCode 104 進行比較
*/