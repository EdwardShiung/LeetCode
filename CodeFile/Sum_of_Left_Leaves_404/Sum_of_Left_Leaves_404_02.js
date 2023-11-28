//[2nd]:Recursive Method

/*
    對於遞歸法，從本題來看，利用前序可以輕易解決。
    前序順序為：中、左、右
    中：處理是否有子節點
    左：一但節點為葉子節點，進行加總
    右：判斷是否有子節點。
        情況一：有左節點，且左節點為葉子節點，將此節點挪入判斷;
        情況二：有右節點，繼續判斷是否為葉子節點。若為右邊葉子節點，則繼續判斷;若為左子節點，則進入中，進行加總

*/

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ?  null : right;
}

var sumOfLeftLeaves = function(root){

    let result = 0;

    if(root === null) return result;
    if(root.left === null && root.right === null) return result;

    const getLeaves = (node) =>{

        //中：左、右子節點為 null，則 return result;
        if(node.left === null && node.right === null){
            return result += node.val;
        }

        //左：
        if(node.left){
            let leftNode = getLeaves(node.left);
        }

        //右：
        if(node.right && node.right.left || node.right && node.right.right){
            let rightNode = getLeaves(node.right);
        }
    }

    getLeaves(root);
    console.log(result);
    return result;

}





let root = new TreeNode(1);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);


sumOfLeftLeaves(root);