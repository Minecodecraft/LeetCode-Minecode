//
//  main.cpp
//  163. Missing Ranges
//
//  Created by Jaylen Bian on 7/26/20.
//  Copyright © 2020 边俊林. All rights reserved.
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
// Solution 1: Copied once but it works
/*
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& vec, int lower, int upper) {
        vector<string> res;
        vector<long> nums = vector<long>(vec.begin(), vec.end());
        nums.push_back((long)upper+1);
        long beg = (long)lower-1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] - beg > 1) {
                string tmp = to_string((long)beg+1);
                if ((long)nums[i] - beg > 2)
                    tmp += "->" + to_string((long)nums[i]-1);
                res.push_back(tmp);
            }
            beg = nums[i];
        }
        return res;
    }
};
 */

// Solution 2: Really simple
class Solution {
    string getRange(long start, long end) {
        return (start == end) ? to_string(start) : to_string(start) + "->" + to_string(end);
    }

public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        for (int i = 0; i <= nums.size(); ++i) {
            long beg = (i == 0) ? (long)lower : (long)nums[i-1]+1;
            long end = (i == nums.size()) ? (long)upper : (long)nums[i]-1;
            if (beg <= end) res.push_back(getRange(beg, end));
        }
        return res;
    }
};

int main() {

    return 0;
}
