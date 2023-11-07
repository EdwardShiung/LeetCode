//[1st]

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

var isSubtree = function(root, subRoot){

    //Base Case: If the main tree is null, there can't be a subtree.
    //Base Case: If the subTree is null, there is no tree to compare.
    if(root ===  null || subRoot === null) return false;
    //Base Case: If Tree & subTree are null, return true
    if(root === null && subRoot === null) return true;


    //Initialize a queue with the main Tree
    let queue = [root];

    //Define a helper(method) to check if they are the same tree or not.
    const isSameTree = (Node_01, Node_02) => {
        //If Node_01 in Tree & Node_02 in subTree are null or not.
        if(Node_01 === null && Node_02 === null) return true;
        if(Node_01 === null || Node_02 === null) return false;
        //If Node_01 & Node_02 are not Null, they will keep going to check left & right tree
        return Node_01.val === Node_02.val && isSameTree(Node_01.left, Node_02.left) && isSameTree(Node_01.right, Node_02.right);
    }

    while(queue.length){
        //Set a pointer for current main Tree
        let current = queue.shift();
        console.log(current)

        //Check the value of current Node in Main and compare with Node in subTree
        //--> If so, check if they are the same tree. (Based on their Current Node, check their left and right tree)
        //--> define a helper(method) to check if they are the same tree or not.
        if(current.val === subRoot.val && isSameTree(current, subRoot)) return true;

        //If no match, Current Node will move on to the Next Node in Main Tree.
        if(current.left !== null) queue.push(current.left);
        if(current.right !== null) queue.push(current.right);
    }
    //If we didn't find it, return false
    console.log(false);
    return false;
}

// [Test Case_01]:
let root = new TreeNode(3);
root.left =  new TreeNode(4);
root.right = new TreeNode(5);
root.left.left = new TreeNode(1);
root.left.right = new TreeNode(2);

let subRoot = new TreeNode(4);
subRoot.left = new TreeNode(1);
subRoot.right = new TreeNode(2);

isSubtree(root, subRoot);


/**
[1st]:
這是我第一次寫出的程式碼，雖然是 Easy 題目，但這題卻佔用了我很多時間：

1. 一但使用了 pop 或 shift，元素會從 Array 中彈出

2. 一但 Array 沒有東西，即使使用 Array.pop() 給予 subCur，指針依舊指導的是 Null
    --> 造成 條件語句 if 判斷無法執行 (Cannot read properties of undefined)

3. 使用 queue : 先進先出概念！！queue 應該搭配 shift() 方法
   使用 stack : 先進後出概念！！stack 應該搭配 pop() 方法

4. 即便以下程式碼可以找到 subTree，但還有一個例外，當 Tree 包含 subTree 對應節點時，卻在之後有其他節點
    可看 LeetCode 572 Cases 第二個例子

[解決方法]：
1. 判斷當前節點值 -->相同，進到 2
2. 判斷當前節點之左節點 (Tree.left 和 subTree.left 是否相同) --> 相同，進到 3
3. 判斷當前節點之右節點 (Tree.right 和 subTree.right 是否相同) --> 相同 return true

--> 以上 3 點皆須符合 --> 使用 &&

var isSubtree = function(root, subRoot){
    if(root === null && subRoot === null) return true;
    if(root ===  null || subRoot === null) return false;

    let queue = [root];
    let subQueue = [subRoot];

    let booleam = false;

    while(queue.length){

        let cur = queue.pop();
        let subCur = subQueue.pop();

        if(cur.val !== subCur.val){

            if(cur.right !== null) queue.push(cur.right);
            if(cur.left !== null) queue.push(cur.left);
            subQueue = [subCur];

            booleam = false;
            console.log(booleam);

        }else{

            if(subCur.right !== null) subQueue.push(subCur.right);
            if(subCur.left !== null) subQueue.push(subCur.left);

            if(cur.right !== null) queue.push(cur.right);
            if(cur.left !== null) queue.push(cur.left);

            booleam = true;
            console.log(booleam);

        }
    }
    console.log(booleam);
    return booleam;
}
 */