//[2nd]: Recursive Method - PostOrder Method

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left,
    this.right = right === undefined ? null : right
}

var maxDepth = function(root){

    //Step 1 : 確認參數和返回值
    const getHeight = (node) =>{

        //Step 2: 確定終止條件：
        if(node === null) return 0;

        //Step 3:確定每一層邏輯關係：
        const leftHeight = getHeight(node.left);
        const rightHeight = getHeight(node.right);
        const height = 1 + Math.max(leftHeight,rightHeight);

        return height;

    }

    console.log(getHeight(root));
    return getHeight(root);
}



let root = new TreeNode(3);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);

// console.log(root);
maxDepth(root);


/**
第一次寫這題時，利用 queue 及 iterative 方式，寫出了結果。

但事實上，我並未真正了解 "深度" 和 "高度區別"。

再者， Recursive Method 分前序、中序 及 後序 三種方法，

但，我尚未體會到，這三種方法，有哪些情況是用，哪些情況並不適用。

--> 需要彙整:

1. 何謂 Tree "深度"？ 何謂 Tree "高度"？
2. Recursive Method
3. 整理實現 Recursive 三部曲

詳情請看 Tree Note

 */

/**

本題利用高度來求深度，是因為"最大深度" 等於 "最大高度"

--> 因此可以透過後序方法來求！！

 */