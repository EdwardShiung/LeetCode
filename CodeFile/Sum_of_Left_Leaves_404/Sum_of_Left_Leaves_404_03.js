//[3rd]:Recursive Method: PostOrder

/*

    本題：參考代碼隨想錄中，後序解法
    後序：左、右、中
    左：判斷左子樹是否為葉子節點，倘若為葉子節點，存入 leftValue
    右：單純判斷是否有葉子節點，倘若有左子節點，則進入 leftValue，再次判斷;倘若為右子節點，繼續判斷。

 */




//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}


var sumOfLeftLeaves = function(root){

    let leftValue = 0;
    let rightValue = 0;
    let result = 0;

    //基本判斷
    if(root === null) return result;
    if(root.left === null && root.right === null) return result;

    //左：
    if(root.left){
        leftValue = sumOfLeftLeaves(root.left);
    }

    if(root.left && root.left.left === null && root.left.right === null){
        leftValue = root.left.val;
    }

    //右：
    if(root.right){
        rightValue = sumOfLeftLeaves(root.right);
    }

    //中：
    result = leftValue + rightValue;

    console.log(result);
    return result;

}


let root = new TreeNode(1);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);


sumOfLeftLeaves(root);