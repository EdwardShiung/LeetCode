//[1st]

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

var isSubtree = function(root, subRoot){
    if(root === null && subRoot === null) return true;
    if(root ===  null || subRoot === null) return false;

    let rootArray = new Array;
    let subRootArray = new Array;
    rootArray.push(root);
    subRootArray.push(subRoot);

    while(rootArray.length){
        if(rootArray.val !== subRootArray.val){
            rootArray.push(rootArray.left);
        }
    }

}

// [Test Case_01]:
let root = new TreeNode(3);
root.left =  new TreeNode(4);
root.right = new TreeNode(5);
root.left.left = new TreeNode(1);
root.left.right = new TreeNode(2);

let subRoot = new TreeNode(4);
subRoot.left = new TreeNode(1);
subRoot.right = new TreeNode(2);

isSubtree(root, subRoot);