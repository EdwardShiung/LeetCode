//[2nd]: Recursive Method - PreOrder

//ES5
function Node(val, children){
    this.val = val;
    this.children = children || [];
}



//前序：中、左、右 --> 此左右統稱為子節點
var maxDepth = function(root){

    //設定初始結果
    let result = 0;

    //Base Case:
    //root === null
    if(root === null) return result;

    //root !== null
    const getDepth = (node, depth) =>{

        //計算中：
        result = Math.max(result, depth);

        //Base Case:
        //無子節點
        if(node.children.length === 0) return result;

        //計算左、右 --> 統稱子節點
        if(node.children.length){
            depth ++;
            for(let i = 0; i < node.children.length; i++){
                getDepth(node.children[i], depth);
            }
            // depth --;
            // console.log(depth)
        }
    }

    //return result
    getDepth(root, 1);
    console.log(result);
    return result;
}





let child_01 = new Node(3, [new Node(5), new Node(6)]);
let child_02 = new Node(2, []);
let child_03 = new Node(4, []);

let root = new Node(1, [child_01, child_02, child_03]);
// let root = new Node(1,[]);
// console.log(root)
maxDepth(root);