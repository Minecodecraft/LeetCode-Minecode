//
//  main.cpp
//  169. Majority Element
//
//  Created by 边俊林 on 2019/10/17.
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
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int& num: nums) cnt[num]++;
        int res, tot = -1;
        for (auto& kv: cnt) {
            if (kv.second > tot)
                res = kv.first, tot = kv.second;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        3,2,3
    };
    int res = sol.majorityElement(nums);
    cout << res << endl;
    return 0;
}
