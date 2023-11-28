//[1st]:Iterative Method


//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}


var sumOfLeftLeaves = function(root){

    let result = 0;

    if(root === null) return result;

    if(!root.left && !root.right) return 0;

    let queue = [root];

    while(queue.length){
        let cur = queue.shift();

        if(cur.left === null && cur.right === null){
            result += cur.val;
        }

        if(cur.left){
            queue.push(cur.left);
        }

        //第一次寫的時候，並沒有考慮周全右邊節點的狀態，因此在一些特殊的Test Case 中，未能夠得到正確的結果
        if(cur.right && cur.right.left || cur.right && cur.right.right){
           queue.push(cur.right);
        }
    }

    console.log(result);
    return result;
}


let root = new TreeNode(1);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);


sumOfLeftLeaves(root);