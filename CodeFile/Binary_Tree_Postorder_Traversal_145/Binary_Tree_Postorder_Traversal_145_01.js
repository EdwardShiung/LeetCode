//[1st]
var postorderTraversal = function(root) {
    let res = [];
    helper(root, res);
    return res;
};

var helper = function(root, res){
    if(root === null) return;
    helper(root.left, res);
    helper(root.right, res);
    res.push(root.val);
}