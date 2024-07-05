#include <iostream>
#include <stack>
using namespace std;

/*
    Queue is FIFO. So, we can implement Queue by two Stacks.
    Ex:
        Stack_01 --> Element In
        Stack_02 --> Element Out
*/


class MyQueue {
public:

    // Initialize the Queue Data Structure
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {};

    // Input Element to stIn
    void push(int x) {
        stIn.push(x);
    }

    // Output Element by stOut
    int pop() {
        if(stOut.empty()) {
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    // Return the top of stOut
    int peek() {
        // We can use pop() function directly.
        int result = this->pop();
        stOut.push(result);
        return result;
    }

    //  Return whether the queue is empty or not.
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};


int main() {
    
    // Initialize a queue
    MyQueue queue;

    // Input some data
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    // Testing is empty or not
    cout << "Is the Queue empty?" << "Answer:" << (queue.empty() ? "Yes": "No" )<< endl;

    // Testing the peek function
    cout << "Testing the peek function: " << (queue.peek()) << endl;

    // Testing the pop function
    int result = queue.pop();
    cout << "Testing the pop function: " << result << endl;

    // Testing the peek function
    cout << "Testing the peek function: " << (queue.peek()) << endl;


    return 0;
}