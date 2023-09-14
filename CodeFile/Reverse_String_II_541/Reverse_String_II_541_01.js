//[1st]:
var reverseStr = function(s, k) {

    let transferStringToArray = s.split('');

    for(let i = 0; i < s.length; i += 2 * k){

        reverse(transferStringToArray, i, Math.min(i + k - 1, s.length - 1))

    }

    return transferStringToArray.join('');
};

var reverse = (arrayString, begin, end) => {

    let tmp;
    while(begin < end){
        tmp = arrayString[begin];
        arrayString[begin] = arrayString[end];
        arrayString[end] = tmp;
        begin ++;
        end --;
    }
}


let s = "abcdefg";
let k = 2;

// reverseStr(s, k);
// reverse(s);

reverseStr(s, k)


// console.log(s);

/*
    1. The biggest different with Reverse String_II_344 is
        leetcode 344 use array to store the string by each cahracter.
        --> Understand how to manipulate string by using Javascript.
            --> transfer string type to array type
        --> Review the concept down below.
 */

//[Reverse a String by Javascript]:

/**
 *  1. Using split() & reduce()
 *  2. Using split() & reduce() & join()
 *  3. Using spread operator
 *  4. Using Array.form() and reverse() method
 *  5. Using spread operator and reduce() method
 *  6. Using for loop
 *  7. Using substring() and a decrementing index
 *  8. Using recursion
 */


//[1] Using split() & reduce()
// let str = 'EdwardShiung practice leetcode everyday.'

// str = str.split("").reduce((pre, curr)=>{
//     pre + curr
//     console.log(pre + curr, "")
// })
// console.log(str)