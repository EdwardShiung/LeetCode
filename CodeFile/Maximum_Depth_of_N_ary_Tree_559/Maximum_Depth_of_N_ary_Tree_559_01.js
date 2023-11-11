//[1st]: Recursive Method - PostOrder


//ES5
function Node(val, children){
    this.val = val;
    this.children = children || [];
}



var maxDepth = function(root){

    let depth = 0;
    //Base Case:
    if(root === null) return depth;
    //root !== null
    //後序：子節點先，才處理中節點
    //先處理所有子節點
    for(let i = 0; i < root.children.length; i++){
        depth = Math.max(depth, maxDepth(root.children[i]));
    }
    //中間節點：
    let result = depth + 1;
    console.log(result);
    return result;
}





let child_01 = new Node(3, [new Node(5), new Node(6)])
let child_02 = new Node(2, []);
let child_03 = new Node(4, []);
let root = new Node(1, [child_01, child_02, child_03]);

// console.log(root);

maxDepth(root)