//[1st]: Using the Set Function
const getSum = num => {
    let total = 0;

    //Understanding how to manipulate the number operation
    while(num != 0){
        let lastDigit = num % 10;
        num = Math.floor(num / 10);
        total += Math.pow(lastDigit, 2);
    }
    return total;
}


var isHappy = function(n) {

    let set = new Set();

    while(n !== 1){
        n = getSum(n);
        if(n !==1 && set.has(n)){
            console.log(false);
            return false;
        }
        set.add(n);
    }
    console.log(true);
    return true;
};

isHappy(33);


/*

    1. I still don't understand why this solution can be corrected.
        const getSum = num => {
            let total = 0;

            while(num != 0){
                let lastDigit = num % 10;
                num = Math.floor(num / 10);
                total += Math.pow(lastDigit, 2);
            }
            return total;
        }


        var isHappy = function(n) {
            let fast = n;
            let slow = n;
            while(1){
                console.log("come")
                fast = getSum(getSum(fast));
                slow = getSum(slow);
                if(fast === slow){
                    console.log(true);
                    return fast === 1;
                }
            }
            console.log(false);
            return false;
        };
    --> Above solution is from youtuber, Andy Gala.

    2. Understanding how to manipulate the number operation.

 */