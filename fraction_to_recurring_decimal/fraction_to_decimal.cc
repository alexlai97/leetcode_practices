#include <iostream>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    long d = denominator;
    long n = numerator;
    long r;
    long q;
    string res;

    // edge cases 
    if ( n == 0 ) {
        res.append(to_string(0));
        return res;
    }
    if ( d == 0 ) return res;
    if ((d < 0) ^ (n < 0)) res.push_back('-');

    // make abs
    d = abs(d);
    n = abs(n);

    q = n/d;
    r = n%d;
    res.append(to_string(q));
    if (r == 0) {
        return res;
    } else {
        res.push_back('.');
    }

    unordered_map<long,int> table;

    while ( r!=0 ) {
        // cout << "r: " << r << endl;
        // already there
        if (table.find(r) != table.end()) {
            res.insert(table[r], "(");
            res.insert(res.end(), ')');
            break;
        } else {
            table[r] = res.size();
            n = r*10;
            q = n/d;
            r = n%d;
            res.append(to_string(q));
        }
    }
    return res;
}

void print_result(int n, int d) {
    cout << "fractionToDecimal(" << n << ", " << d << ") = " <<fractionToDecimal(n,d) << endl;
}

int main() {
    // print_result(0,3);
    // print_result(2,1);
    // print_result(2,3);
    // print_result(1,9);
    // print_result(11,9);
    print_result(1,333);
}
