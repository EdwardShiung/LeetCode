//[1st]: LeetCode 12 Integer to Roman

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

//Using the function return string to solve the problem
var intToRoman = function(num) {

    const thounsand = ["", "M", "MM", "MMM"];
    const hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC","DCCC", "CM"];
    const tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
    const ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];

    let result = thounsand[Math.floor(num / 1000)] + hundreds[Math.floor(Math.floor(num % 1000) / 100)] + tens[Math.floor(Math.floor(num % 100)/ 10)] + ones[num % 10];

    console.log(result);
    return result;
};

intToRoman(1994);