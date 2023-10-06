//[1st]
var preorderTraversal = function(root) {

    let res = [];
    helper(root, res);
    console.log(res);
    return res;

};

var helper = function(root, res){
    if(!root) return;
    res.push(root.val);
    helper(root.left, res);
    helper(root.right, res);
}



let root = [1,null,2,3];

preorderTraversal(root);