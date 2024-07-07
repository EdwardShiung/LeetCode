#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        
        // Verify the string
        stack<char> stackValid;
        
        // result store another string
        string results = "";

        // Store the Non-duplicated character
        for(char c:s) {
            if(stackValid.empty() || c != stackValid.top()) {
                stackValid.push(c);
            }else{
                stackValid.pop();
            }
        }

        // Make the result from stackValid
        while(!stackValid.empty()) {
            results += stackValid.top();
            stackValid.pop();
        }

        // Reverse results
        reverse(results.begin(), results.end());
    
    return results;
    }
};


int main() {
    Solution solution;


}