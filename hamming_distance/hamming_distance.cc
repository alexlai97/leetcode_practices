#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int sum = 0;
    while (n!=0) {
        sum ++;
        n &= (n-1);
    }
    return sum;
}

int hammingDistance(int x, int y) {
    return hammingWeight(x^y);
}

void print_res(int x, int y) {
    cout << "hammingDistance(x: " << x <<
        ", y: " << y << "): " << hammingDistance(x,y) << endl;
}
int main() {
    print_res(1,4);
}
