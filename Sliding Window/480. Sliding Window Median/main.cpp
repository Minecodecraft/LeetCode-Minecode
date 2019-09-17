//
//  main.cpp
//  480. Sliding Window Median
//
//  Created by 边俊林 on 2019/9/17.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<double> res;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
            if (i >= k) {
                mp[nums[i-k]]--;
                if (mp[nums[i-k]] == 0) mp.erase(nums[i-k]);
            }
            if (i+1 >= k) {
                int step = (k) / 2, laststep;
                auto lit = mp.begin();
                laststep = step;
                while (laststep) {
                    while (lit->second == 0) ++lit;
                    if (laststep >= lit->second) laststep -= (lit++)->second;
                    else laststep = 0;
                }
                auto rit = mp.rbegin();
                laststep = step;
                while (laststep) {
                    while (rit->second == 0) ++rit;
                    if (laststep >= rit->second)
                        laststep -= (rit++)->second;
                    else laststep = 0;
                }
                double mid = ((double)lit->first + (double)rit->first) / 2.0;
                res.push_back(mid);
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        2,3,4
//        1,3,-1,-3,5,3,6,7
//        2147483647,2147483647
        1, 2
    };
//    int k = 3;
//    int k = 2;
    int k = 1;
    auto res = sol.medianSlidingWindow(nums, k);
    cout << res.size() << endl;
    return 0;
}
