//[1st]:


//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : this.val;
    this.left = left === undefined ? null : this.left;
    this.right = right === undefined ? null : this.right;
}
