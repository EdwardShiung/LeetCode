//[1st]: LeetCode 12 Integer to Roman


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
     * Function Name: intToRoman Function
     * Description: The function will transfer Integer to Roman. By adding parameter, it will return an String.
     * Author: Tian Yu (Edward) Shiung
     * Student ID: stianyu99
     * Code Editor: Visual Studio Code
     */
    public String intToRoman(int num) {

        String[] thousand = {"", "M", "MM", "MMM"};
        String[] hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        String[] tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        String[] ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        String result = thousand[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];

        System.out.println(result);
        return result;
    }

    public static void main(String[] args){
        new Solution().intToRoman(1994);
    }
}