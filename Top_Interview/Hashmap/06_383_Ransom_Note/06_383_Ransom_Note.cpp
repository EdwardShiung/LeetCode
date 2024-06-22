#include <iostream>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Using Array to record the english characters
        int record[26] = {0};

        // Record the characters from ransomNote
        for(int i = 0; i < ransomNote.size(); i++) {
            int cal = ransomNote[i] - 'a';
            record[cal]++;
        }

        // Record the characters from magazin
        // If meet the same character, we record it, but if not, we don't do anything!
        for(int j = 0; j < magazine.size(); j++) {
            int cal = magazine[j] - 'a';
            if(record[cal]) record[cal]--;
        }

        // Determine the results. 
        // If all the record is zero, it means that there is at least one way that magazine could construct ransomNote.
        for(int k = 0; k < 26; k++) {
            if(record[k]) return false;
        }

        // If pass the above determination, it return true
        return true;

    }
};