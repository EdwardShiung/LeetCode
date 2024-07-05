#include <iostream>
#include <stack>
using namespace std;


/*

    Ex: 
        string = (){};
            --> true
    Ex:
        string = (];
            --> false
    
    [Thought]:
    --> so we can use stack to determine whether the input symbols are correct.
    --> If a left parenthesis is encountered, push the corresponding right parenthesis onto the stack.
    --> If a right parenthesis is encountered, there are two situations:
        --> If the stack is empty, or the top of stack is not the current parenthesis, it means that the matching has failed.
        --> If the matching is successful, pop the top element from the stack.

*/



class Solution {
public:
    bool isValid(string s) {

        // Check the number of symbols are odd or even.
        if((s.size() % 2) != 0) {
            cout << false << endl;
            return false;
        }

        // Create a stack 
        stack<char> stackValid;
        for(int i = 0; i < s.size(); i++) {
            // If a left parenthesis is encountered, push the corresponding right parenthesis onto the stack.
            if(s[i] == '(') stackValid.push(')');
            else if(s[i] == '[') stackValid.push(']');
            else if(s[i] == '{') stackValid.push('}');
            // If a right parenthesis is encountered, there are two situations happened:
            else{
                // If the stack is empty, or the top of stack is not the current parenthesis, it means that the matching has failed.
                if(stackValid.empty() || stackValid.top() != s[i]) {
                    cout << false << endl;
                    return false;
                }
                // If the matching is successful, pop the top element from the stack.
                stackValid.pop();
            }
        }

        // [Sol_01] If the string is a valid parentheses, the stackValid will be empty.
        // if(stackValid.empty()) {
        //     return true;
        // }else{
        //     return false;
        // }

        // [Sol_02]
        cout << "Is the string is valid parentheses? " << (stackValid.empty() ? "Yes!" : "No!") << endl;
        return  stackValid.empty();

    }
};

int main() {

    Solution solution;

    string s = "({";

    bool results = solution.isValid(s);

    return 0;
}

