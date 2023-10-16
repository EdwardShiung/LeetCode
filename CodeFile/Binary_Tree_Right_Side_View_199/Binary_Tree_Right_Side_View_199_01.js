//[1st]

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

var rightSideView = function(root) {

    let result = new Array();

    if(root === null) return result;

    let queue = [root];

    let cur = null;

    while(queue.length){
        let size = queue.length;
        //determine odd or event
        let i = 0;
        while(size --){
            cur = queue.shift();
            if(cur !== null){
                if(i % 2 === 0){
                    result.push(cur.val);
                }
                if(cur.right !== null) queue.push(cur.right);
            }
            i ++;
        }
    }

    console.log(result);
    return result;

};

let root = new TreeNode(1);
// root.left = new TreeNode(2);
root.right = new TreeNode(2);
// root.right = new TreeNode(3);
// root.left.right = new TreeNode(5);
// root.right.right = new TreeNode(4);

// console.log(root);
rightSideView(root);