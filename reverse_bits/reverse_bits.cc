#include <iostream>
#include <bitset>
#include <boost/utility/binary.hpp>

using namespace std;

// https://leetcode.com/articles/reverse-bits/
uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

void print_res(uint32_t n) {
    cout << "reverseBits(" << bitset<32>(n) << "): " << 
        bitset<32>(reverseBits(n)) << endl;
}

int main() {
    print_res(BOOST_BINARY(00000010 10010100 00011110 10011100));
    print_res(BOOST_BINARY(11111111 11111111 11111111 11111101));
}
