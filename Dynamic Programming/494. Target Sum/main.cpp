//
//  main.cpp
//  494. Target Sum
//
//  Created by 边俊林 on 2019/9/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/target-sum/
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
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, 0, 0, S);
    }

private:
    int dfs(vector<int>& nums, int idx, int sum, int target) {
        if (idx == nums.size()) return sum == target ? 1 : 0;

        int cnt = 0;
        cnt += dfs(nums, idx+1, sum + nums[idx], target);
        cnt += dfs(nums, idx+1, sum - nums[idx], target);
        return cnt;
    }
};

int main() {

    return 0;
}
