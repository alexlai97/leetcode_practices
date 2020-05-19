#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char,int> table = {
    {'I' , 1},
    {'V' , 5},
    {'X' , 10},
    {'L' , 50},
    {'C' , 100},
    {'D' , 500},
    {'M' , 1000}
};

int romanToInt(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
        char cur = s[i];
        char next = s[i+1];

        if (table[cur] < table[next]) {
            sum += table[next] - table[cur];
            i+=1;
        } else {
            sum += table[cur];
        }
    }
        
    return sum;
}

int main() {
    string s = "MCMXCIV";
    cout << "romanToInt(\"" << s << "\"): " << romanToInt(s) << endl;

}
