//[2nd]

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}


var invertTree = function(root){

    if(root === null) return null;

    let stack = [root];

    while(stack.length){
        let cur = stack.pop();
        let temp = cur.left;
        cur.left = cur.right;
        cur.right = temp;

        if(cur.left !== null) stack.push(cur.left);
        if(cur.right !== null) stack.push(cur.right);

    }

    console.log(root);
    return root;

};

let root = new TreeNode(2);
root.left = new TreeNode(1);
root.right = new TreeNode(3);

invertTree(root);