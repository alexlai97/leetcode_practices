#include <iostream>
#include <utility>      // std::pair, std::make_pair
#include <stack> 
using namespace std;

class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
    }
    
    void push(int x) {
        if (st.empty()) {
            st.push(make_pair(x,x));
        } else {
            int m = st.top().second;
            st.push(make_pair(x,min(m,x)));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        // assume stack is not empty
        return st.top().first;
    }
    
    int getMin() {
        // assume stack is not empty
        return st.top().second;
    }
};

void print_num(int num) {
    cout << num << endl;
}

int main() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    print_num(minStack->getMin()); // return -3
    minStack->pop();
    print_num(minStack->top());    // return 0
    print_num(minStack->getMin()); // return -2

    delete minStack;
}
