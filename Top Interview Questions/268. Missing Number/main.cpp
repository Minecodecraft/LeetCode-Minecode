//
//  main.cpp
//  268. Missing Number
//
//  Created by 边俊林 on 2019/10/26.
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
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return (nums.size()+1)*nums.size()/2 - accumulate(nums.begin(), nums.end(), 0);
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        3, 0, 1
//        9,6,4,2,3,5,7,0,1
        0, 1
    };
    int res = sol.missingNumber(nums);
    cout << res << endl;
    return 0;
}
