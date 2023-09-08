//[1st]
// var twoSum = function(nums, target) {
//     let map = new Map();

//     for(let i = 0; i < nums.length; i++){
//         if((target - nums) !== undefined){
//             return map.keys();
//         }
//         map.set(i, target - nums[i]);
//     }
//     console.log(map.keys());
//     return map.keys();
// };


function twoSum(nums, target) {
    //create Hash Table
    const numIndexMap = {};

    for (let i = 0; i < nums.length; i++) {
        //Calculate current rest number
        const complement = target - nums[i];
        // if rest number in the Hash table, retun the index
        console.log("Complement: "+complement);
        if (complement in numIndexMap) {
            console.log([numIndexMap[complement], i])

            return [numIndexMap[complement], i];
        }
        //Keep the index and number in the hash table
        console.log(numIndexMap);
        numIndexMap[nums[i]] = i;

    }

    //if no sum solution, throw error
    throw new Error("No two sum solution");
}



// var twoSum = function (nums, target) {
//     let hash = {};
//     for (let i = 0; i < nums.length; i++) {  // 遍历当前元素，并在map中寻找是否有匹配的key

//         if (hash[target - nums[i]] !== undefined) {
//         console.log([i, hash[target - nums[i]]])
//         return [i, hash[target - nums[i]]];
//       }
//       hash[nums[i]] = i;   // 如果没找到匹配对，就把访问过的元素和下标加入到map中
//     }
//     console.log([]);
//     return [];
//   };



/*
    1. Understanding how to use map object.
    2. I have to try how to use map object to solve this


 */


//Basic for map object:

// const map_01 = ([
//     [1,"one"],
//     [2,"two"],
//     [3,"three"]
// ])

// console.log(myMap.keys(1));



// const map_02 = new Map();
// map_02.set(1,"one");
// map_02.set(2,"two")

// console.log(map_02)
// console.log(map_02.get(1));     //one
// console.log(map_02.values())    //{ 'one', 'two' }

// console.log(map_02.keys())      //{ 1, 2 }
// console.log(map_02.entries())

let nums = [2,11,7,15];
let target = 9;

twoSum(nums,target);
