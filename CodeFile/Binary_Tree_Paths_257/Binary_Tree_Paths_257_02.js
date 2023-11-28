//[2nd]: Iterative Method

/**
 這一題雖然是 Easy 題目，但真的要我用 Iterative Method 時，真的想破頭！！
 加上，while 回圈判斷應該使用陣列長度(length)，而不是只是判斷是否有值
 */

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}


var binaryTreePaths = function(root){

    if(root === null) return;
    //遍歷節點
    let queueTree = [root];
    //保存路徑
    let queuePath = [''];
    //保存結果
    let result = new Array();

    while(queueTree.length){
        //cur pointer 讀取 queueTree 節點
        let cur = queueTree.shift();

        console.log(cur)
        //先將該節點存放到路徑
        let path = queuePath.shift();

        //如果沒有任何子節點，直接將路徑存入結果中
        if(!cur.left && !cur.right){
            result.push(path + cur.val);
        }


        path += cur.val + '->';

        //左邊節點
        if(cur.left){
            queueTree.push(cur.left);
            queuePath.push(path);
        }

        //右邊節點
        if(cur.right){
            queueTree.push(cur.right);
            queuePath.push(path);
        }

    }
    console.log(result);
    return result;
}



let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.right = new TreeNode(5);

binaryTreePaths(root);
