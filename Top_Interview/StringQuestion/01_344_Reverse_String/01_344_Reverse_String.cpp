#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            // 暫存
            char temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }

        for(int i = 0; i < s.size(); i++) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
};



int main() {

    //創建 陣列
    vector<char> s = {'h','e','l','l','o'};

    // 引用 Solution Class
    Solution solution;
    solution.reverseString(s);


    return 0;
}
