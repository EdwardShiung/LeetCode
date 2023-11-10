//[4th]: ES6 : Recursive Method
// Using ES6 Class Method to Create the Result


//Create TreeNode by Class
class TreeNode{
    constructor(val, left, right){
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ? null : right;
    }
}


class Solution{
    constructor(){
        this.result = 0;
    }


    //計算maxDepth
    maxDepth(root){
        //root === null
        if(root === null) return this.result;

        //root !== null
        this.getDepth(root, 1);
        //計算出總共的 depth
        return this.result;
    }

    //計算各層 Depth (順序：中-->左-->右)
    getDepth(node, depth){
        //先計算 中：
        this.result = Math.max(this.result, depth);

        //計算左、右節點：
        //先設定沒有子節點，直接返回 result
        if(node.left === null && node.right === null) return result;

        //計算 左：
        if(node.left){
            //計算進入下一層，先行將深度 + 1
            depth ++;
            this.getDepth(node.left, depth);
            //葉子節點無子節點，還回 + 1
            depth --;
        }

        //計算 右：
        if(node.right){
            //計算進入下一層，先行將深度 + 1
            depth ++;
            this.getDepth(node.right, depth);
            //葉子節點無子節點，還回 + 1
            depth --;
        }
    }
}



let root = new TreeNode(3);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);

// console.log(root);
let result = new Solution()
console.log(result.maxDepth(root));