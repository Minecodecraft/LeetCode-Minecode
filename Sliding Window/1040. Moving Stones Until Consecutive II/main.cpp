//
//  main.cpp
//  1040. Moving Stones Until Consecutive II
//
//  Created by 边俊林 on 2019/9/24.
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
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int l = 0, len = stones.size();
        int small = len, large = max(
             stones[len-1]-len+1-stones[1]+1,
             stones[len-2]-len+1-stones[0]+1);
        for (int r = 0; r < len; ++r) {
            while (stones[r] - stones[l] + 1 > len) ++l;
            // 对于 1 2 3 4 10 的Corner case，可以1->6 10 -> 5，总共两次
            if (r-l+1 == len-1 && stones[r]-stones[l]+1 == len-1)
                small = min(small, 2);
            else
                small = min(small, len-(r-l+1));
        }
        return {small, large};
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        6,5,4,3,10
        7,4,9
//        100,101,104,102,103
    };
    auto res = sol.numMovesStonesII(nums);
    cout << res[0] << "," << res[1] << endl;
    return 0;
}
