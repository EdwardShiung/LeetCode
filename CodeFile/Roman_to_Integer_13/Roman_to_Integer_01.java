import java.util.HashMap;
import java.util.Map;

//[1st]: LeedCode 13 Roman to Integer
/*
        "I" : 1,
        "V" : 5,
        "X" : 10,
        "L" : 50,
        "C" : 100,
        "D" : 500,
        "M" : 1000
 */


 class Solution {

    /*
     * Function Name: romanToInt Function
     * Description: The function will transfer Roman Code to Integer. By adding parameter, it will return an integer.
     * Author: Tian Yu (Edward) Shiung
     * Student ID: stianyu99
     * Code Editor: Visual Studio Code
     */
    public int romanToInt(String s) {

        //Using HashMap to store letters and corrseponding values to solve this problem
        Map<Character, Integer> dic = new HashMap<>();
        dic.put('I',1);
        dic.put('V',5);
        dic.put('X',10);
        dic.put('L',50);
        dic.put('C',100);
        dic.put('D',500);
        dic.put('M',1000);

        //Calculate the total
        int total = 0;

        for(int i = 0; i < s.length(); i ++){

            char curr = s.charAt(i);
            char next = (i + 1 < s.length()) ? s.charAt(i + 1) : '\0';


            int currValue = dic.get(curr);
            int nextValue = (next != '\0') ? dic.get(next) : 0;

            if (currValue < nextValue) {
                total -= currValue;
            } else {
                total += currValue;
            }
        }

        System.out.println(total);
        return total;
    }


    public static void main(String[] args){
        new Solution().romanToInt("VI");
    }
};
