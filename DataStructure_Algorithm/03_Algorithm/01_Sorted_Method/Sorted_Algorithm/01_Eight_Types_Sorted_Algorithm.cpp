#include <iostream>
using namespace std;

class SortedAlgorithm {
public:

    // 使用指針方式，統一接口調用（如此，其他實做出來的 function，就可以透過此 function 統一調度）
                                                    // 指針引用：“新加指針名稱” 替換 “函數指針名稱”，其餘不變
    void printResult(vector<int>& vec, int vecSize, void (*sortFunction)(vector<int>&, int)){
        sortFunction(vec, vecSize);
        for(int i = 0; i < vecSize; i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    // 1. Bubble Sort (冒泡排序)
    static void bubbleSort(vector<int>& vec, int vecSize) {
        // 相鄰兩個元素比較
        // 每一次從頭比到尾 
            // 這裡可以優化（不用每一次都比到最後，因為最大的一定在最右邊）
            // 因此，每一次的比較，都會少一次！
        for(int i = 0; i < vecSize - 1; i++) {
            for(int j = 0; j < vecSize - i - 1; j++) {
                if(vec[j] > vec[j + 1]) {
                    swap(vec, j, j + 1);
                }
            }
        }
    }

    // 2. Selection Sort(選擇排序)
    
private:
    static void swap(vector<int>& vec, int i, int j) {
        int temp = vec[j];
        vec[j] = vec[i];
        vec[i] = temp;
    }
};


int main() {
    vector<int> vec = {1,3,5,7,9,2,4,6,8,10};
    
    SortedAlgorithm SortedAlgorithm;

    SortedAlgorithm.printResult(vec, vec.size(), SortedAlgorithm.bubbleSort);

    return 0;
}