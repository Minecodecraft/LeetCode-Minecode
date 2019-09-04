//
//  main.cpp
//  354. Russian Doll Envelopes
//
//  Created by 边俊林 on 2019/9/3.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/russian-doll-envelopes/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//

// Solution 1
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() <= 0) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp;
        for (int i = 0; i < envelopes.size(); ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if (it != dp.end())
                *it = envelopes[i][1];
            else
                dp.push_back(envelopes[i][1]);
        }
        return dp.size();
    }

private:
    struct {
        bool operator() (const vector<int>& a, const vector<int>& b) const {
            return a[0] < b[0] || (a[0] == b[0] && a[1] >= b[1]);
        }
    } cmp;
};

// Solution 2
/*
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() <= 0) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp (envelopes.size(), 1);
        for (int i = 0; i < envelopes.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

private:
    struct {
        bool operator() (const vector<int>& a, const vector<int>& b) const {
            return a[0] < b[0] || (a[0] == b[0] && a[1] <= b[1]);
        }
    } cmp;
};
 */

int main() {
    Solution sol = Solution();
    vector<vector<int>> nums = {

//        {5,4}, {6,4}, {6,7}, {2,3}
//        {5,4}, {6,4}, {6,7}, {2,3}, {7 ,8}
        {1,1}
    };
    int res = sol.maxEnvelopes(nums);
    cout << res << endl;

    return 0;
}
