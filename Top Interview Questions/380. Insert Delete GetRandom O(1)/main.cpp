//
//  main.cpp
//  380. Insert Delete GetRandom O(1)
//
//  Created by 边俊林 on 2019/10/31.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.count(val)) return false;
        arr.push_back(val);
        hash[val] = arr.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash.count(val) == 0) return false;
        int idx = hash[val];
        swap(arr[idx], arr[arr.size()-1]);
        hash[arr[idx]] = idx;
        arr.pop_back();
        hash.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % arr.size();
        return arr[idx];
    }
    
private:
    vector<int> arr;
    unordered_map<int, int> hash;
};

int main() {
    RandomizedSet sol = RandomizedSet();
    cout << sol.insert(0) << endl;
    cout << sol.insert(1) << endl;
    cout << sol.remove(0) << endl;
    cout << sol.insert(2) << endl;
    cout << sol.remove(1) << endl;
    cout << sol.getRandom() << endl;
    return 0;
}
