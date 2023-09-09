


var fourSumCount = function(nums1, nums2, nums3, nums4) {


    const twoSumMap = new Map();

    let count = 0;

    for(const n1 of nums1){
        for(const n2 of nums2){
            let sum = n1 + n2;
            twoSumMap.set(sum, (twoSumMap.get(sum) || 0) + 1);
        }
    }
    console.log(twoSumMap);
    for(const n3 of nums3){
        for(const n4 of nums4){
            let sum = n3 + n4;
            count += (twoSumMap.get(0-sum) || 0);
        }
    }
    console.log(count);
    return count;

};


let nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2];
fourSumCount(nums1, nums2, nums3, nums4);






/*



 */




// const eventsMap = {};

// eventsMap[0] = "one";
// eventsMap[1] = "two";



// console.log(eventsMap);     //{ '0': 'one', '1': 'two'}

// delete eventsMap[1];
// console.log(eventsMap);     //{'0': 'one'}


// const eventsMap = new Map();

// eventsMap.set(0, "one") ;

// eventsMap.set(1, "two") ;

// console.log(eventsMap);         //Map(2) { 0 => 'one', 1 => 'two' }

// eventsMap.delete(1)

// console.log(eventsMap);         //Map(1) { 0 => 'one' }