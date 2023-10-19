//[1st]

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}


var maxDepth = function(root){

    if(root ===  null) return 0;

    let queue = [root];
    let depth = 0;

    while(queue.length){
        let = size = queue.length;
        while(size --){
            let cur = queue.shift();
            if(cur.left !== null) queue.push(cur.left);
            if(cur.right !== null) queue.push(cur.right);
        }
        depth ++;
    }
    console.log(depth)
    return depth;
}


let root = new TreeNode(3);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);

maxDepth(root);

/*
依舊在第一次寫時候，會出現 left: Cannot read properties of undefined (reading 'left')
--> 循環判斷部分，沒設置好
*/
