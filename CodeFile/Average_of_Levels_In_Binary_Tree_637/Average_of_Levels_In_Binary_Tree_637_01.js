//[1st]
//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}


var averageOfLevels = function(root) {

    let result = [];
    if(root ===  null) return result;
    let queue = [root];
    let cur = null;

    while(queue.length){
        let size = queue.length;
        let sum = 0;
        let count = 0;

        while(size --){
            cur = queue.shift();
            console.log(cur)
            if(cur !==  null){
                count ++;
                sum += cur.val
                if(cur.left !== null) queue.push(cur.left);
                if (cur.right !== null) queue.push(cur.right);
            }

        }

        result.push(sum / count);
    }

    console.log(result);
    return result;
};

let root = new TreeNode(3);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);

//  console.log(root);

averageOfLevels(root);
