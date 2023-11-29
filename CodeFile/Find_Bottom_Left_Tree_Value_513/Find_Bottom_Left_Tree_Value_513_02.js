//[2nd]: Recursive Method

/*
    本題，無論前序、中序、後序 皆可得到答案！！
        Why?
        ANS:    1. 因為本題並未處理中節點邏輯
                2. 本題最重要的是找到最深且最左邊的子節點

                ps. 會發現，本題沒有中間節點邏輯處理，原因為上述。
 */

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

var findBottomLeftValue = function(root) {
    if(root === null) return null;

    //Step 1: 設定全域變數
    let maxDepth = 0;
    let resNode = 0;

    //Step 1: 參數及回傳值
    const traversal = (node, depth) =>{

        //Step 2: 終止條件
        if(node.left === null && node.right === null){
            if(depth >  maxDepth){
                maxDepth = depth;
                resNode = node.val
            }
        }

        //Step 3: 單層邏輯
        //左：
        if(node.left){
            depth ++;
            traversal(node.left, depth);
            //回朔 backtracking
            depth --;
        }

        //右：
        if(node.right){
            depth ++;
            traversal(node.right, depth);
            //回朔 backtracking
            depth --;
        }
    }

    traversal(root, 1);
    console.log(resNode);
    return resNode;
}

let root = new TreeNode(2);
root.left = new TreeNode(1);
root.right = new TreeNode(3);
// root.left.left = new TreeNode(4);
// root.right.left = new TreeNode(5);
// root.right.right = new TreeNode(6);
// root.right.left.left = new TreeNode(7);

findBottomLeftValue(root);