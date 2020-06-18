#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <stack>
using namespace std;

int myAtoi(string str) {
    long res = 0;
    bool negative = false;

    int i = 0;
    while (i < str.length()) {
        if (str[i] == '+' ||
                str[i] == '-' ||
                (str[i] >= '0' && str[i] <= '9')) {
            break;
        } else if (!isspace(str[i])) {
            return 0;
        }
        i++;
    }


    if (str[i] == '+') {
        i++;
    } else if (str[i] == '-') {
        negative = true;
        i++;
    } 
        

    while (i < str.length()) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (negative) {
                res = res * 10 - (str[i] - '0');
                if (res < INT_MIN) return INT_MIN;
            } else {
                res = res * 10 + (str[i] - '0');
                if (res > INT_MAX) return INT_MAX;
            }
        } else {
            break;
        }
        i++;
    }

    return res;
}

void print_res(string str) {
    int res = myAtoi(str);
    cout << "myAtoi(\'" << str << "\"): " << res << endl;
}

int main() {
    print_res("42");
    print_res(" +0042");
    print_res("  -42");
    print_res("  +42");
    print_res("  + 42");
    print_res("  - 42");
    print_res("4193 with words");
    print_res("words and 987");
    print_res("-91283472332");
    print_res("-");
}
