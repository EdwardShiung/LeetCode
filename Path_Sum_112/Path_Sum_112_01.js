//[1st]: Path Sum: Recursive method

/**
 Question:

 Given the root of a binary tree and an integer targetSum,
 return true if the tree has a root-to-leaf path such that
 adding up all the values along the path equals targetSum.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

Example 3:
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.

 */

//ES6 Version

class TreeNode{
    constructor(val, left, right){
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ?  null : right;
    }
}


let hasPathSum = (root, targetSum) => {


    // 確認根節點存在
    if(!root) return false;

    // 如果是葉子節點，則檢查總和是否等於目標值
    if (!root.left && !root.right) {
        return targetSum === root.val;
    }

    // 遞迴地檢查左右子樹
    return hasPathSum(root.left, targetSum - root.val) || hasPathSum(root.right, targetSum - root.val);
}



let root = new TreeNode(5);
root.left = new TreeNode(4);
root.right = new TreeNode(8);

root.left.left = new TreeNode(11);
root.left.left.left = new TreeNode(7);
root.left.left.right = new TreeNode(2);

root.right.left = new TreeNode(13);
root.right.left.left = new TreeNode(4);
root.right.left.left = new TreeNode(1);

// console.log(root);

hasPathSum(root,22);