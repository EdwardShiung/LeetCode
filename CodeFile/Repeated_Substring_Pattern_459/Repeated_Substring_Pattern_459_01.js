//[1st]:

/*
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 */

var repeatedSubstringPattern = function(s) {

    let len = s.length;

    if(len === 0){
        console.log(false);
        return false;
    }


    for(let subStrlength = 1; subStrlength <= len / 2; subStrlength  ++){

        //only remainder === 0 才進入 if

        if(len % subStrlength === 0){

            //rep check
            const rep = (len / subStrlength);
            //prepare to store the possible string
            let subString = '';

            //store substring
            for(let i = 0; i < subStrlength; i ++){
                subString += s[i];
            }


            //判斷是否為重複子字串
            let booleam = true;


            //verify is repeated or not
            //從第一組之後開始判斷（因為，第一組已經先分給 subString）
            for(let i = 1; i < rep; i ++){
                for(let j = 0; j < subStrlength; j ++){
                    if(s[i * subStrlength + j] !== subString[j]){
                        booleam = false;
                        break;
                    }
                }
                if (!booleam) {
                    break;
                }

            }

            if(booleam === true){
                console.log(true);
                return true;
            }
        }

    }
    console.log(false);
    return false;

};


let s = 'aba';
repeatedSubstringPattern(s);
