#include <iostream>

using namespace std;
// looked at solution 
// explanation: https://youtu.be/qq64FrA2UXQ
int getSum(int a, int b) {
        
    if (b == 0) return a;
    int sum = a ^ b;
    int carry = (unsigned int)(a & b) << 1;
    return getSum(sum, carry);
}

void print_res(int a, int b) {
    cout << "getSum(" << a << ", " << b << ")= " << getSum(a,b) << endl;
}

int main() {
    print_res(1,2);
    print_res(-2,3);
}
