//[1st]

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

var isSameTree = function(p, q){
    //前提假設
    if(p === null && q === null) return true;
    if(p === null || q === null) return false;

    //比較節點
    let queue = new Array;
    queue.push(p);
    queue.push(q);
    while(queue.length){
        let pNode = queue.shift();
        let qNode = queue.shift();
        if(pNode === null && qNode === null) continue;
        if(pNode === null || qNode === null) return false;
        if(pNode.val !== qNode.val) return false
        queue.push(pNode.left);
        queue.push(qNode.left);
        queue.push(pNode.right);
        queue.push(qNode.right);
    }
    console.log(true);
    return true;
}

// [Test Case_01]:
let p = new TreeNode(1);
p.left = new TreeNode(2);

let q = new TreeNode(1)
q.right = new TreeNode(2);

//[Test Case_02]:
// let p = new TreeNode(1);
// p.left = new TreeNode(2);
// p.right = new TreeNode(3);

// let q = new TreeNode(1);
// q.left = new TreeNode(2);
// q.right = new TreeNode(3);

isSameTree(p,q);