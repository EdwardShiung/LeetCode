#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*

    The logic of question is the same as the LeetCode 1047.
    Understanding how to use the stack to solve the problem is very important.

    ps. Understanding how to transfer the string to integer by C++11.
        All of that is in the <string> header file
            1. Transferring "string" to "ing"
                --> stoi
            2. Transferring "string" to "long"
                --> stol
            3. Transferring "string" to "long long"
                --> stoll
            4. Transferring "string" to "unsigned long"
                --> stoul
            5. Transferring "string" to "unsigned long long"
                --> stoull
            6. Transferring "string" to "float"
                --> stof
            7. Transferring "string" to "double"
                --> stod
            8. Transferring "string" to "long double"
                --> stold
                
        ps. "sto" stand for string to [type]
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Create a Verify 
        stack<int> stackValid;

        for(int i = 0; i < tokens.size(); i++) {
             if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num_01 = stackValid.top();
                stackValid.pop();
                int num_02 = stackValid.top();
                stackValid.pop();
                if(tokens[i] == "+") stackValid.push(num_02 + num_01);
                if(tokens[i] == "-") stackValid.push(num_02 - num_01);
                if(tokens[i] == "*") stackValid.push(num_02 * num_01);
                if(tokens[i] == "/") stackValid.push(num_02 / num_01);
             }else{
                // string type transfer to integer
                stackValid.push(stoi(tokens[i]));
             }
        }

        int result = stackValid.top();
        stackValid.pop();
        return result;
    }
};


int main() {
    Solution solution;

    vector<string> tokens = {"4","13","5","/","+"};

    cout << solution.evalRPN(tokens) << endl;

    return 0;
}