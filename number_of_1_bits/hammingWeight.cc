#include <iostream>
#include <bitset>
#include <boost/utility/binary.hpp>

using namespace std;

// https://leetcode.com/articles/number-1-bits/
int hammingWeight(uint32_t n) {
    int sum = 0;
    while (n!=0) {
        sum ++;
        n &= (n-1);
    }
    return sum;
}

void print_res(uint32_t n) {
    cout << "hammingWeight(" << bitset<32> (n) << "): "<< hammingWeight(n) << endl;
}

int main() {
    print_res(BOOST_BINARY(00000000 00000000 00000000 00001011));
    print_res(BOOST_BINARY(00000000 00000000 00000000 10000000));
    print_res(BOOST_BINARY(11111111 11111111 11111111 11111101));
}
