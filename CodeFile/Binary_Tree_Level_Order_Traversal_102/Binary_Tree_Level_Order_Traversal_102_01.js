//[1st]

//ES5
function TreeNode(val, left , right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}


var levelOrder = function(root) {

    let result = [];

    if(root === null) return result;

    let queue = [root];
    let cur;
    let size = 0;

    while(queue.length){
        size = queue.length;

        let temp = [];

        //Limitation is each layer elements
        while(size --){

            cur = queue.shift();
            if(cur !== null )  temp.push(cur.val);
            if(cur.left !== null) queue.push(cur.left);
            if(cur.right !== null) queue.push(cur.right);
        }
        result.push(temp);
    }

    console.log(result);
    return result;

};



//Test Case 1
let root = new TreeNode(3);
root.right = new TreeNode(20);
root.left = new TreeNode(9);
root.left.right = new TreeNode(77);
root.left.left = new TreeNode(88);
root.right.right = new TreeNode(7)
root.right.left = new TreeNode(15);




let array = [1,2,3,4];

// array.shift();

// console.log(root)
levelOrder(root);