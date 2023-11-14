//[1st]: Iterative Method

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}


var countNodes = function(root){
    let count = 0;
    if(root === null) return count;

    let queue = [root];

    while(queue.length){
        let cur = queue.shift();
        count ++;
        if(cur.left !== null) queue.push(cur.left);
        if(cur.right !== null) queue.push(cur.right);
    }
    console.log(count);
    return count;
}


let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);
root.right.left = new TreeNode(6);

// console.log(root);

countNodes(root);