#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
private:
    vector<int> v;
    unordered_map<int,int> m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val)) return false;

        v.push_back(val);
        m[val]=v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!m.count(val)) return false;

        int last = v.back();
        int val_index = m[val];
        m[last]  = val_index;
        v[val_index] = last;
        v.pop_back();
        m.erase(val);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};


int main() {
    RandomizedSet* rs = new RandomizedSet();
    cout << (rs->insert(1) ? "True":"False") << endl;
    cout << (rs->insert(2) ? "True":"False") << endl;
    cout << (rs->insert(3) ? "True":"False") << endl;
    cout << (rs->insert(4) ? "True":"False") << endl;
    cout << (rs->remove(2) ? "True":"False") << endl;
    cout << "Random: " << rs->getRandom() << endl;
    cout << "Random: " << rs->getRandom() << endl;
    cout << "Random: " << rs->getRandom() << endl;
    cout << "Random: " << rs->getRandom() << endl;
    cout << "Random: " << rs->getRandom() << endl;
    cout << "Random: " << rs->getRandom() << endl;
    cout << "Random: " << rs->getRandom() << endl;
    delete rs;
}
