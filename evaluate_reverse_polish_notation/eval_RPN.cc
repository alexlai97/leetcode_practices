#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

int eval(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}

bool isOperator(string t) {
    return t == "+" || t == "-" || t == "*" || t == "/";
}

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (auto t: tokens) {
        if (isOperator(t)) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(eval(b,a,t[0]));
        } else {
            st.push(stoi(t));
        }
    }

    return st.top();
}

void print_res(vector<string> &tokens) {
    print_vector("tokens",tokens);
    cout <<  "evalRPN: " << evalRPN(tokens) << endl;
}

int main() {

    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};


    print_res(tokens1);
    print_res(tokens2);
    print_res(tokens3);
}
