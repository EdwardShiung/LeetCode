//[1st]
var intersection = function(nums1, nums2) {

    let slow = 0;
    let fast = 0;
    let tmp = new Array();

    for(let i = slow; i < nums1.length; i ++){
        for(let j = fast; j < nums2.length; j ++){
            if(nums1[i] === nums2[j]){
                console.log(nums1[i]);
                tmp.push(nums1[i]);
                break;
            }
        }
    }
    // console.log(tmp);
    let arrayData = Array.from(new Set(tmp))
    console.log(arrayData);
    return arrayData;
};



let array_01 = [1,2,2,1];
let array_02 = [2,2];

intersection(array_01, array_02);

/*
    1. Review how to use push.
        --> I have to review an push method theory.
    2. Review how to use Set method
        --> I have to review how to build an Set method.
    3. I have to understand how many ways could do the unique element in array or object.

    [Results]:
    Runtime     89ms;       Beats 5.02% of users with JavaScript;
    Memory      45.42mb;    Beats 5.02% of users with JavaScript;

    --> The results is quite bad. I have to optimize later.
 */
