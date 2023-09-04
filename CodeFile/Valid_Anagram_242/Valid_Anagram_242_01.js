//[1st]:
var isAnagram = function(s, t) {

    let fast = 0;
    let slow = 0;
    let boolean = true;

    if(s.length != t.length) return false;


    for(let i = slow; i < s.length; i++){
        for(let j = fast; j < t.length; j++){
            if(s[i] === t[j]){
                // console.log("s "+s[i])
                boolean = true;
                // console.log(boolean);
                t = t.replace(t[j],"");
                // console.log("Character: "+t);
                // console.log("time "+j);
                break;
            }else if(j === t.length - 1){

                boolean = false;
                // console.log(boolean);
                return  boolean;
            }else{
                boolean = false;
            }
            // console.log(t.length);
        }

    }
    // console.log(boolean);
    return boolean;
}

let s = 'aacc';
let t = 'ca';

isAnagram(s,t);

/*
    1. I think about this solution in my first time, which is really bad in time complexity and space complexity.
    2. I believe it could be optimize.

    3. Understand how to use the replace API.

    [Results]:
        Runtime     307ms;      Beats 5.01% of users with JavaScript;
        Memory      73.2mb;    Beats 5.18% of users with JavaScript;

 */
