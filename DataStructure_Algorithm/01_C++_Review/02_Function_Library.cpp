#include <iostream>
using namespace std;

/*
    1. substr function
    -   std::string substr(size_t pos = 0, size_t len = npos) const;
        - 1st parameter is starting position
        - 2nd parameter is length of string
*/

int main() {
    string s = "abcdef";
    // Using substr function
    // retrieve the substr: cdef

    /*
        a   b   c   d   e   f
        0   1   2   3   4   5
    */
    int start = 2;
    int end = 5;
    string substr = s.substr(start, end - start + 1);
    // Print Result
    cout << substr << endl; // cdef

    return 0;
}