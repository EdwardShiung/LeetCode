//[3rd]: Iterative Method

//Iterative Method 可以用 Array, stack, queue 進行層序遍歷
//這邊選用 queue

//ES5

function Node(val, children){
    this.val = val;
    this.children = children || [];
}



var maxDepth = function(root){

    let result = 0;
    //Base Case:
    if(root === null) return result;

    let queue = [root];

    //記錄層級：
    let depth = 0;

    //層序遍歷：
    while(queue.length){
        let size = queue.length;
        depth ++;

        for(let i = 0; i < size; i++){
            let cur = queue.shift();
            for(let j = 0; j < cur.children.length; j++){
                if(cur.children[j]){
                    queue.push(cur.children[j]);
                    console.log(cur.children[j])
                }
            }
        }

    }

    result = depth;
    console.log(result);
    return result;
}



// let child_01 = new Node(3, [new Node(5), new Node(6)]);
// let child_02 = new Node(2, []);
// let child_03 = new Node(3, []);

// let root = new Node(1, [child_01, child_02, child_03]);

let child_01 = new Node(2,[]);
let child_02 = new Node(3, [new Node(6,[]), new Node(7,[new Node(11, [new Node(14,[])])])]);
let child_03 = new Node(4, [new Node(8, [new Node(12,[])])]);
let child_04 = new Node(5, [new Node(9, [new Node(13,[])]), new Node(10,[])])

let root = new Node(1, [child_01, child_02, child_03, child_04])

console.log(root)
maxDepth(root);

// console.log(root);
