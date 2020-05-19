#include <iostream>
using namespace std;
int mySqrt(int x) {
    if ( x == 1 ) return 1;
    int i = 0;
    int j = x;
    unsigned long long guess = 0;
    while (true) {
        unsigned long long square1 = guess * guess;
        unsigned long long square2 = (guess+1) * (guess+1);
        if ( square1 <= x && square2 > x ) {
            break;
        }
        if (square1 < x) {
            i = guess;
            guess = (guess + j)/2;
        } else {
            j = guess;
            guess = (guess + i)/2;
        }
    }
    return guess;
}

int main() {
    int x = 4;
    cout << mySqrt(x) << endl;
}
