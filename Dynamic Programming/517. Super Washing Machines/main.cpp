//
//  main.cpp
//  517. Super Washing Machines
//
//  Created by 边俊林 on 2019/9/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/super-washing-machines/
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
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        int len = machines.size();
        if (sum % len != 0) return -1;

        vector<int> dp (machines.begin(), machines.end());
        unordered_set<int> vis;
        bool changed = true;
        int cnt = 0, cursum = 0, avg = sum / len;

        while (changed) {
            changed = false;
            vis.clear();
            ++cnt;
            // iterate with preorder
            cursum = 0;
            for (int i = 0; i < len; ++i) {
                cursum += dp[i];
                if (i > 0 && dp[i] > 0 && cursum-dp[i] < avg*(i)) {
                    // move to left
                    dp[i]--; dp[i-1]++;
                    changed = true;
                    vis.insert(i);
                }
            }
            // iterate with inorder
            cursum = 0;
            for (int i = len-1; i >= 0; --i) {
                cursum += dp[i];
                // move to right
                if (i < len-1 && dp[i] > 0 && cursum-dp[i] < avg*(len-i-1)) {
                    if (vis.count(i) > 0) { // need to change but not now
                        changed = true;
                    } else {
                        dp[i]--; dp[i+1]++;
                        changed = true;
                    }
                }
            }
        }
        return cnt-1;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 0, 5
//        0,3,0
    };
    int res = sol.findMinMoves(nums);
    cout << res << endl;
    return 0;
}
