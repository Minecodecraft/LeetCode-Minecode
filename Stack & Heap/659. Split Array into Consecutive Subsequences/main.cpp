//
//  main.cpp
//  659. Split Array into Consecutive Subsequences
//
//  Created by 边俊林 on 2019/10/9.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/split-array-into-consecutive-subsequences/
\* ------------------------------------------------------ */

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
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, tail;
        for (auto& elem: nums) cnt[elem]++;
        for (auto& elem: nums) {
            if (cnt[elem] == 0) continue;
            cnt[elem]--;
            if (tail[elem-1])
            tail[elem-1]--, tail[elem]++;
            else if (cnt[elem+1] && cnt[elem+2])
            cnt[elem+1]--, cnt[elem+2]--, tail[elem+2]++;
            else return false;
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1,2,3,3,4,5
//        1,2,3,3,4,4,5,5
        1,2,3,4,4,5
    };
    bool res = sol.isPossible(nums);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
