#include <iostream>
using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {

    if (str1 + str2 != str2 + str1) {
      return "";
    }

    int sizeStr1 = str1.size();
    int sizeStr2 = str2.size();

    while (sizeStr2 > 0) {
      int tmp = sizeStr2;
      sizeStr2 = sizeStr1 % sizeStr2;
      sizeStr1 = tmp;
    }

    return str1.substr(0, sizeStr1);
  }
};
