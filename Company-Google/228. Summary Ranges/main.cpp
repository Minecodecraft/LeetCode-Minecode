//
//  main.cpp
//  228. Summary Ranges
//
//  Created by Jaylen Bian on 9/6/20.
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
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        nums.push_back(INT_MIN);
        long pre = nums[0], cur = nums[0];
        vector<string> res;
        for (int i = 1; i < nums.size(); ++i) {
            if ((long)nums[i-1] + 1 != nums[i]) {
                if (nums[i-1] == pre) {
                    res.push_back(to_string(pre));
                } else {
                    res.push_back(to_string(pre) + "->" + to_string(nums[i-1]));
                }
                pre = nums[i];
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
