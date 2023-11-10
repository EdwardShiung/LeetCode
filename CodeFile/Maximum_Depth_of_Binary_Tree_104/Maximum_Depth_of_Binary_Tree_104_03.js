//[3rd]: Recursive Method - PreOrder Method


//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left,
    this.right = right === undefined ? null : right
}


var maxDepth = function(root){

    // 因為返回為一個固定值(多深)
    let result = 0
    //root === null：
    if(root === null) return result;

    //root !== null：
        //Step 1: 確認參數及返回值：
    const getDepth = (node, depth) =>{


            //前序是 中, 左, 右：
            //先處理 中：
            result = Math.max(this.result, depth)

            //Step 2: 再處理 左 和 右：

            //確認終止條件：
            if(node.left === null && node.right === null) return 0;

            //Step 3: 確認每一層邏輯關係：

            //左
            if(node.left){
                //進去遞迴前，深度先 + 1
                depth ++;
                getDepth(node.left, depth);
                //出來遞迴，必須要 - 1，因為左邊葉子節點，並沒有下一個節點，所以原本先加的，要還回來！！
                depth --;
            }

            //右
            if(node.right){
                //進去遞迴前，深度先 + 1
                depth ++;
                getDepth(node.right, depth);
                //出來遞迴，必須要 - 1，因為左邊葉子節點，並沒有下一個節點，所以原本先加的，要還回來！！
                depth --;
            }
    }

    //返回結果：
    getDepth(root, 1)
    console.log(result);
    return result;
}




let root = new TreeNode(3);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);

// console.log(root);
maxDepth(root);
