//[1st]
var inorderTraversal = function(root) {
    let res = [];
    helper(root, res);
    return res;
};

const helper = function(root, res){
    if(root === null) return;
    helper(root.left, res);
    res.push(root.val)
    helper(root.right, res);
}