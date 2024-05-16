//[1st]: Path Sum: Recursive Method
/*
LeetCode Question 113:

Introduction:

Given the root of a binary tree and an integer targetSum,
return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node.
A leaf is a node with no children.

Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:

Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:

Input: root = [1,2], targetSum = 0
Output: []

 */
//ES6 Version

/*
    思路：這道題並沒有中路思路，因此前序、中序、後序皆可以實作。

 */

class TreeNode{
    constructor(val, left, right){
        this.val = undefined ? 0 : val;
        this.left = undefined ? null : left;
        this.right = undefined ? null : right;
    }
}


let pathSum = (root, targetSum) => {

    let res = [];
    if(root === null) return res;
    traversal(root, targetSum - root.val, [root.val], res)
    console.log(res);
    return res;

}

//Step 1：確認參數和回傳值 --> 此回傳 Array 以存取 路徑
let traversal = (node, count, path, res) => {
    //Step 2: 中指條件
    //遇到葉子節點，並且成功找到了 targetSum
    if(node.left === null && node.right === null && count === 0){
        //注意：要"深拷貝" 不能寫 res.push(path);
        res.push([...path]);
        //找到後，向上至 root 回溯
        console.log("true");
        return true;
    }
    //遇到葉子節點，但是沒有找到 targetSum 直接返回
    if(node.left === null && node.right === null && count !== 0){
        console.log("false");
        return false
    }
    //Step 3: 單層循環
    //向左循環：
    if(node.left){
        path.push(node.left.val);
        //遞歸
        traversal(node.left, count - node.left.val, path, res);
        //回溯
        path.pop();
    }
    //向右循環：
    if(node.right){
        path.push(node.right.val);
        traversal(node.right, count - node.right.val, path, res);
        path.pop();
    }
    console.log("false");
    return false;
}


let root = new TreeNode(5);
root.left = new TreeNode(4);
root.right = new TreeNode(8);

root.left.left = new TreeNode(11);
root.right.left = new TreeNode(13);
root.right.right = new TreeNode(4);

root.left.left.left = new TreeNode(7);
root.left.left.right = new TreeNode(2);

root.right.right.left = new TreeNode(5);
root.right.right.right = new TreeNode(1);

// console.log(root);

pathSum(root, 22)
