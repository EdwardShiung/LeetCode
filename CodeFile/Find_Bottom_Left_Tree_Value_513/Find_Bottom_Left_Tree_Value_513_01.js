//[1st]: Iterative Method

/*

解題思路：
    1. 本題第一個反應（簡單）：
        使用迭代法：層序遍歷

    1-1. 本題題意為 Given the root of a binary tree, return the leftmost value in
    last row of the tree.
    --> leftmost value 的意思是"最靠近左邊的值"，並且題目要求在"最後一行找到最靠近左邊的值"
        --> 如果最深的葉子節點為右邊葉子節點，沒有左邊葉子節點，則右邊葉子節點即為答案。
        --> 第一次看到這題，以為是一直往左邊找葉子節點，並找到左邊最深的葉子節點，請小心！！！！！！！！

    2.  若使用遞歸法(較難)：
            深度利用前序：從上到下查
            高度利用後序：從下到上查

    2-2. 本題，無論前序、中序、後序 皆可得到答案！！
        Why?
        ANS:    1. 因為本題並未處理中節點邏輯
                2. 本題最重要的是找到最深且最左邊的子節點
 */

//ES5
function TreeNode(val, left, right){
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
}

var findBottomLeftValue = function(root) {

    if(root === null) return null;

    let queue = [root];

    let result = 0;

    while(queue.length){

        let size = queue.length;

        for(let i = 0; i < size; i ++){

            let cur = queue.shift();

            if(i === 0) result = cur.val;

            if(cur.left) queue.push(cur.left);
            if(cur.right) queue.push(cur.right);

        }
    }

    console.log(result);
    return result;
};

let root = new TreeNode(2);
root.left = new TreeNode(1);
root.right = new TreeNode(3);
// root.left.left = new TreeNode(4);
// root.right.left = new TreeNode(5);
// root.right.right = new TreeNode(6);
// root.right.left.left = new TreeNode(7);

findBottomLeftValue(root);

// let arr = [1,2,3];
// arr.shift();
// arr.push(4)
// arr.shift()
// console.log(arr) //[3,4]