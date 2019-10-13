//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2019/10/13.
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
    int maxEqualFreq(vector<int>& nums) {
        int res = 0;
        vector<int> cnt (1e5+10, 0);
        map<int, int> freq;

        for (int i = 0; i < nums.size(); ++i) {
            if (cnt[nums[i]] > 0) {
                if (--freq[cnt[nums[i]]] == 0)
                    freq.erase(cnt[nums[i]]);
            }
            cnt[nums[i]]++;
            freq[cnt[nums[i]]]++;
            if (freq.size() == 1) {
                if ((freq.count(1) > 0)
                    || (freq.begin()->second) == 1)
                    res = i;
            } else if (freq.size() == 2) {
                if ((freq.count(1) > 0 && freq[1] == 1)
                    || (freq.rbegin()->first-1 == freq.begin()->first && freq.rbegin()->second == 1))
                    res = i;
            }
        }

        return res+1;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        2,2,1,1,5,3,3,5
//        1,1,1,2,2,2,3,3,3,4,4,4,5
//        1,1,1,2,2,2
//        10,2,8,9,3,8,1,5,2,3,7,6
//        1, 2
//        1, 1
//        1, 1, 2, 2
        1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,42,21,45,27,78,39,78,24,47,60,22,33,45,18,56,91,93,66,79,65,43,7,57,63,74,25,11,14,100,95,19,3,22,18,94,52,91,33,95,16,93,63,65,8,88,51,47,7,51,77,36,48,89,72,81,75,13,69,9,31,16,38,34,76,7,82,10,90,64,28,22,99,40,88,27,94,85,43,75,95,86,82,46,9,74,67,51,93,97,35,2,49
    };
    int res = sol.maxEqualFreq(nums);
    cout << res << endl;
    return 0;
}
