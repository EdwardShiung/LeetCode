//[1st]:Using the Split Function

var reverseWords = function(s) {
    console.log("Origin String: " + s);
    s = s.split(' ');
    let count = 0;
    let newString = [];
    for(let i = 0; i < s.length; i ++){
        if(s[i] === ''){
            continue;
        }
        newString[count] = s[i];
        count ++;
    }

    console.log(newString);


    let begin = 0;
    let end = newString.length - 1;
    let tmp;
    while(begin < end){

        if(newString[begin] === ' '){
            begin ++;
        }
        if(newString[end] === ' '){
            end --;
        }

        tmp = newString[begin];
        newString[begin] = newString[end];
        newString[end] = tmp;
        begin ++;
        end --;
    }
    console.log(newString)
    newString = newString.join(' ');
    console.log(newString);
    return newString;
};

let s = "the sky is    blue";
reverseWords(s);


/*
    1. Understanding how to use split and join by JavaScript.
    2. Using the Split to re-origanize the sentance is not a good solution.
    3. The time complexity and space complexity are worse.
 */
