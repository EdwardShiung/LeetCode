#include <iostream>
#include <queue>
using namespace std;

/*
    Compared to the "implement Queue using Stack", 
    we just need use one queue to complete the task.
*/

class MyStack {
public:
    // Initialize the Stack Data Structure
    queue<int> que;
    MyStack() {};

    // Input the data
    void push(int x) {
        que.push(x);
    }

    // Output the data
    int pop() {
        // Record the numbers of data
        int size = que.size();
        // The reason why we deduct here first is that if only one element in the queue, we don't push back.
        size--;
        // The front data push to the back.
        while(size--) {
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;
    }

    // Check the top of data
    int top() {
        return que.back();
    }

    // Check the stack is empty or not
    bool empty() {
        return que.empty();
    }
};

int main() {
    MyStack stack;
    return 0;
}