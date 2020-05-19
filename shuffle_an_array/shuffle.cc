#include <iostream>
#include <vector>
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <utility>

using namespace std;

class Solution {
private:
    vector<int> orig_config;
    vector<int> array;
    random_device rd; // obtain a random number from hardware
    mt19937 eng; // seed the generator
    uniform_int_distribution<> distr; // define the range

public:
    Solution(vector<int>& nums) {
        this->orig_config = nums;
        this->array = this->orig_config;
        this->eng = mt19937(rd());
        this->distr = uniform_int_distribution<>(0,nums.size()-1);
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        array = orig_config;
        return array;
    }


    vector<int> shuffle() {
        for (int i = 0; i < array.size(); ++i) {
            int rand_i = distr(eng);
            swap(array[i], array[rand_i]);
        }
        return array;
    }
};

void print_vector(string name, vector<int> &v) {
    cout << name << ": [";
    for (auto i: v) cout << i << ", ";
    cout << "]" << endl;
}

int main() {
    vector<int> nums = { 1,2,3,4,5,6,7,8,9,10 };

    print_vector("nums", nums);

    Solution* s = new Solution(nums);
    vector<int> v_shuffle = s->shuffle();
    print_vector("v_shuffle", v_shuffle);
    vector<int> v_reset = s->reset();
    print_vector("v_reset", v_reset);

}

