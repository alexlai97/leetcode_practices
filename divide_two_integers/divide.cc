#include <iostream>
#include <stdlib.h>
#include <climits>
using namespace std;

// solution from https://www.programcreek.com/2014/05/leetcode-divide-two-integers-java/
int divide(int dividend, int divisor) {

    if (divisor == 0) return 0;
    if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
    if (divisor == 1) return dividend;

    long pDividend = (long)abs(dividend);
    long pDivisor = (long)abs(divisor);
    
    int result = 0;
    while (pDividend >= pDivisor) {
        int numShift = 0;
        while (pDividend >= (pDivisor << numShift)) {
            numShift ++;
        }

        numShift --;
        result += 1 << numShift;
        pDividend -= pDivisor << numShift;
    }

    if (( dividend > 0 && divisor > 0 ) ||
            ( dividend < 0 && divisor < 0 )) {
        return result;
    } else {
        return -result;
    }
}

void print_divide(int dividend, int divisor) {
    cout << dividend << "/" << divisor << " = " << divide(dividend, divisor) << endl;
}

int main() {
    print_divide(8,2);
    print_divide(10,3);
    print_divide(7,-3);
    print_divide(-2147483648,1);
}
