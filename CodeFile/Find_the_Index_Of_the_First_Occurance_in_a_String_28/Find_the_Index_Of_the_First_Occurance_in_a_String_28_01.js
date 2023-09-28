//[1st]:
var strStr = function(haystack, needle) {

    let j = 0;
    let next = new Array(needle.size);
    next = getNext(next, needle);
    for(let i = 0; i < haystack.length; i ++){
        while(j > 0 && haystack[i] != needle[j]){
            j = next[j - 1];
        }

        if(haystack[i] === needle[j]){
            j++
        }

        if(j === needle.length){
            console.log(i - needle.length + 1);
            return (i - needle.length + 1);
        }
    }
    console.log(-1);
    return -1;
};

var getNext = (next, needle) => {
//initialize
    //prefix j = 0
    let j = 0;
    //next index = 0 --> 0
    next = [0];
    for(let i = 1; i < needle.length; i ++){
        while(j > 0 && needle[i] != needle[j]){
            j = next[j - 1];
        }

        if(needle[i] === needle[j]){
            j ++;
        }
        next[i] = j;
    }
    console.log(next);
    return next;
}



let haystack = 'aabaabaaf';
let needle = 'aabaaf';
// let next = [];
// getNext(next, needle);
strStr(haystack, needle);