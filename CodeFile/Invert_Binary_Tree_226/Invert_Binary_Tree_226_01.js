//[1st]

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

var invertTree = function(root){

    if(root ===  null) return null;

    let left = invertTree(root.left);
    let right = invertTree(root.right);

    root.right = left;
    root.left = right;

    console.log(root);
    return root;
};


let root = new TreeNode(2);
root.left = new TreeNode(1);
root.right = new TreeNode(3);

invertTree(root);

/**
 * 題目要的是返回一個 Tree，並不是返回一個陣列(Array):
 * var invertTree = function(root){

    if(root ===  null) return [];

    let queue = [root];
    let result = new Array();

    while(queue.length){
        let size = queue.length;
        while(size --){
            let cur = queue.shift();
            if(cur !== null) result.push(cur.val);
            if(cur.right !== null) queue.push(cur.right);
            if(cur.left !== null) queue.push(cur.left);
        }
    }
    root = result;
    console.log(root);
    return root;
};
---> 因此，此程式碼是錯誤的。
 *
 */