//[1st]

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}



var minDepth = function(root){


    if(root === null) return 0;

    let queue = [root];
    let depth = 1;

    while(queue.length){
        let size = queue.length;
        //判斷是否找到最小深度
        let minDepthFound = false;

        while(size --){

            let cur = queue.shift();
            if((cur.left === null) && (cur.right === null)){
                minDepthFound = true;
                break;
            }

            if(cur.left !== null) queue.push(cur.left);
            if(cur.right !== null) queue.push(cur.right);
        }
        //找到最小深度十，返回
        if(minDepthFound) {
            console.log(depth);
            return depth
        };
        depth ++;

    }
    //如果未找到最小深度，返回當前深度
    console.log(depth);
    return depth;
}


let root = new TreeNode(3);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);

minDepth(root);