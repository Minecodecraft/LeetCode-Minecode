//
//  main.cpp
//  486. Predict the Winner
//
//  Created by 边俊林 on 2019/9/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/predict-the-winner/
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
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums, 0, nums.size()-1, 0, 0, true);
    }

private:
    bool canWin(vector<int>& nums, int l, int r, int mysum, int opsum, bool equalIsWin) {
        if (l > r) return false;
        if (l == r) return equalIsWin && mysum + nums[l] >= opsum;

        if (!canWin(nums, l+1, r, opsum, mysum + nums[l], !equalIsWin)
            || !canWin(nums, l, r-1, opsum, mysum + nums[r], !equalIsWin))
            return true;
        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 5, 2
        1, 5, 233, 7
//        1, 5, 1, 5
//        1, 1
    };
    bool res = sol.PredictTheWinner(nums);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
