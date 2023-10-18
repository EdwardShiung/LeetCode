//[1st]

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}





var largestValues = function(root){
    let result = [];
    if(root === null) return result;
    let queue = [root]; // same as queue.push(root);

    while(queue.length){
        let size = queue.length;
        let max = queue[0].val;
        while(size --){
            let cur = queue.shift();

            if(cur !== null){
                max = max > cur.val ? max : cur.val;
                if(cur.left !== null) queue.push(cur.left);
                if(cur.right !== null) queue.push(cur.right);

            }
        }
        result.push(max);
    }

    console.log(result);
    return result;
}



// let root = new TreeNode(1);
// root.left = new TreeNode(3);
// root.left.left = new TreeNode(5);
// root.left.right = new TreeNode(3);
// root.right = new TreeNode(2);
// root.right.right = new TreeNode(9);



let root = new TreeNode(0);
root.left = new TreeNode(-1);
// root.left.left = new TreeNode(5);
// root.left.right = new TreeNode(3);
// root.right = new TreeNode(2);
// root.right.right = new TreeNode(9);
// console.log(root);

largestValues(root);