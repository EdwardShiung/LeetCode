//[1st]

//ES5
// function Node(val, children){
//     this.val = val;
//     this.children = children || [];
// }

//ES6
class Node{
    constructor(val, children){
        this.val = val;
        this.children = children || [];
    }
}


var levelOrder = function(root) {

    let result = [];

    if (root === null) return result;

    let queue = [root];

    while(queue.length){
        let size = queue.length;
        let temp = new Array();
        while(size --){
            let node = queue.shift();
            temp.push(node.val);

            //[Key Point]:Not node left or node right instead of using for loop for children
            for(let item of node.children){
                if(item !== null) queue.push(item);
            }
        }
        result.push(temp);
    }
    console.log(result);
    return result;
};


let child_01 = new Node(3, [new Node(5), new Node(6)]);
let child_02 = new Node(2, []);
let child_03 = new Node(4, []);

let root = new Node(1, [child_01, child_02, child_03]);




// console.log(root);

levelOrder(root);