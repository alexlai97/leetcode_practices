#include <iostream>
#include <string>
#include <math.h>       /* log */
using namespace std;

//https://leetcode.com/articles/power-of-three/
bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
}

void print_res(int n) {
    bool flag = isPowerOfThree(n);
    cout << "isPowerOfThree(" << n << "): " << (flag?"Yes":"No") << endl;
}

int main() {
    print_res(3);
    print_res(81);
}
