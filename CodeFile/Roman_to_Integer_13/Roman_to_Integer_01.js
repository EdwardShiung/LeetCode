//[1st]: LeetCode 13 Roman to Integer

//Using function return integer to solve this problem
var romanToInt = function(s) {

    //Storing letters and corresponding values to the object
    const dic = {
        "I" : 1,
        "V" : 5,
        "X" : 10,
        "L" : 50,
        "C" : 100,
        "D" : 500,
        "M" : 1000
    }

    //Calculate the total value
    let total = 0;

    //Using the for loop to iterate the Roman String
    for(let i = 0; i < s.length; i ++){

        let curr = s[i];
        let next = s[i + 1];

        //If the Curr Value is less than Next, we could dedcue the current value by total, otherwise, we can add the total.
        if(dic[curr] < dic[next])
        {

            total -= dic[curr];
            console.log(total);
        }
        else
        {

            total += dic[curr];
            console.log(total);
        }

    }
    console.log(total);
    return total;

};


romanToInt("VI");
