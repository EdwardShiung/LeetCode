//[1st]:
var reverseString = function(s) {


    let endPoint = s.length - 1;
    let startPoint = 0;
    let tmp;

    while(endPoint > startPoint){
        tmp = s[endPoint];
        s[endPoint] = s[startPoint];
        s[startPoint] = tmp;
        endPoint --;
        startPoint ++;
    }
    // console.log(s);
    return s;

};



let s = ["h", "e", "l", "l", "o"];

reverseString(s);