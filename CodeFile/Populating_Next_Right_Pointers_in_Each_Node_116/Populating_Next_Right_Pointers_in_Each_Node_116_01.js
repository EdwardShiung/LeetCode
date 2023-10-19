//[1st]

//ES5
function Node(val, left, right, next){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
    this.next = next === undefined ? null : next;
}




var connect = function(root) {
    if (root === null) return root;
    let queue = [root];
    while (queue.length) {
        let n = queue.length;
        for (let i = 0; i < n; i++) {
            let node = queue.shift();
            if (i < n-1) {
                node.next = queue[0];
            }
            node.left && queue.push(node.left);
            node.right && queue.push(node.right);
        }
    }
    console.log(root);
    return root;
};

// var connect = function(root){

//     //基本判斷：
//     if(root === null) return root;
//     let queue = [root];

//     while(queue.length){
//         let size = queue.length;

//         //個別層循環
//         for(let i = 0; i < size; i ++){

//             let node = queue.shift();

//             if(i < size - 1){
//                 node.next = queue[0];
//             }
//             if(node.left !== 0) queue.push(node.left);
//             if(node.right !== 0) queue.push(node.right);
//         }
//     }
//     console.log(root)
//     return root;
// }

let root = new Node(1);
root.left = new Node(2);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right = new Node(3);
root.right.left = new Node(6);
root.right.right = new Node();

// console.log(root);
connect(root);
