#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_pair(char c1, char c2) {
    return 
        (c1 == '{' && c2 == '}') ||
        (c1 == '[' && c2 == ']') ||
        (c1 == '(' && c2 == ')');
}

bool is_left(char c) {
    return c == '{' || c == '(' || c == '[';
}
bool is_right(char c) {
    return c == '}' || c == ']' || c == ')';
}

bool isValid(string s) {
    stack<char> st;
    for (auto c: s) {
        if (is_left(c)) {
            st.push(c);
        } else if (st.empty()) {
            return false;
        } else if (is_right(c)) {
            char top = st.top();
            if (is_pair(top,c)) {
                st.pop();
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    if (st.empty()) {
        return true;
    } else {
        return false;
    }
}

void print_res(string s) {
    cout << "isValid(\"" << s << "\"): " << 
        (isValid(s)? "True" : "False") << endl;
}
int main() {
    print_res("()");
    print_res("()[]{}");
    print_res("(]");
    print_res("([)]");
    print_res("{[]}");
    print_res("(");
    print_res("]");
}
