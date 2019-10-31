//
//  main.cpp
//  384. Shuffle an Array
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
// Knuth Suffle Algorithm
// https://gaohaoyang.github.io/2016/10/16/shuffle-algorithm/
class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = arr;
        for (int i = res.size()-1; i >= 0; --i) {
            int idx = rand() % (i+1);
            swap(res[idx], res[i]);
        }
        return res;
    }
    
private:
    vector<int> arr;
};

int main() {

    return 0;
}
