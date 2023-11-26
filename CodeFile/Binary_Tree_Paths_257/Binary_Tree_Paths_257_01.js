//[1st]: Resursive Method

/*

本題思路為 遞歸法中的前序：中、左、右

 */

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

var binaryTreePaths = function(root){

    //result
    let result = new Array();

    if(root === null) return;

    traversal(root, '', result);

    console.log(result);
    return result;

}


//Step 1: 確認參數及返回值：(node型態為 TreeNode; path 型態為 string; resArr 型態為 string [])
const traversal = (node, path, resArr) =>{

    //中：單層邏輯：中間部分處理於此，說明請看下面
    path += String(node.val);

    //Step 2: 確認終止條件：
    if(node.left === null && node.right === null){
        resArr.push(path);
        return;
    }

    //Step 3:單層邏輯：
    //中：原本該寫這裡，但如果寫這，葉子節點就不會在 path 中，並且不會傳給最終的 resArr

    //左：
    if(node.left !== null){
        traversal(node.left, path + '->', resArr)
    }

    //右：
    if(node.right !== null){
        traversal(node.right, path + '->', resArr);
    }

    return resArr;

}





let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.right = new TreeNode(5);

// console.log(root);
binaryTreePaths(root);