/*

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]

 */
//[1st Trial]
var generateMatrix = function(n) {

    //Initialized the matrix
    let matrix = new Array(n).fill().map(() => new Array(n).fill(0));

    //Calculate the loop for matrix
    let loop = Math.floor(n / 2);

    //starting point
    let startX = 0;
    let startY = 0;

    //it will decrease the offset
    let offset = 1
    //give first element number
    let count = 1;

    //the middle of the array (if odd matrix)
    let middle = Math.floor(n / 2);

    while(loop > 0){
        let j = 0
        let i = 0;

        //from left to right (Upper line)
        for(j = startY; j < n - offset; j ++){
            matrix[startX][j] = count++;
        }

        //from top to down (right line)
        for(i = startX; i < n - offset; i ++){
            matrix[i][j] = count ++;
        }

        //from righ to left (bottom line)
        for(; j > startY; j --){
            matrix[i][j] = count ++;
         }

        // from down to up (left right)
        for(; i > startX; i --){
            matrix[i][j] = count ++;
        }

        startX ++;
        startY ++;
        offset ++;
        loop --;
    }

    if(n % 2 != 0){
        matrix[middle][middle] = count;
    }

    // console.log(matrix);
    return matrix;
};


/*
    1. Using JavaScript to generate power of N

        function powerOfN (n){
            for(let i = 1; i <= n * n; i++){
                let nums = i;
                console.log(nums);
            }
        }

        powerOfN(2);    //1,2,3,4
        powerOfN(3);    //1,2,3,4,5,6,7,8,9
        powerOfN(1);    //1

    2. Create the new Array and initialize all elements are 0.

        --> new Array(2).fill(0) --> [0,0]

        Create the Matrix 3x3 or 4x4 or NxN

        Ex: new Array(5).fill().map(() => new Array(5).fill(0))
            [
                [ 0, 0, 0, 0, 0 ],
                [ 0, 0, 0, 0, 0 ],
                [ 0, 0, 0, 0, 0 ],
                [ 0, 0, 0, 0, 0 ],
                [ 0, 0, 0, 0, 0 ]
            ]

    3.  Math.floor --> it could rounds down and return
            Ex: 2.7 --> 2
        Math.round --> it could round to the nearest integer
            Ex: 2.7 --> 3

    [Results]:
    Runtime     59ms;       Beats 46.77% of users with JavaScript;
    Memory      41.98mb;    Beats 58.46% of users with JavaScript;
 */

generateMatrix(5);
