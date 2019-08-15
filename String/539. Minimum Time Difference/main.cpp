//
//  main.cpp
//  539. Minimum Time Difference
//
//  Created by 边俊林 on 2019/8/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/minimum-time-difference/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
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
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int res = INT_MAX, n = timePoints.size();
        for (int i = 0; i < n; ++i) {
            int diff = abs(getDiff(timePoints[(i-1+n) % n], timePoints[i]));
            diff = min(diff, maxtime-diff);
            res = min(res, diff);
        }
        return res;
    }

private:
    const int maxtime = 24*60;
    int getDiff(const string& s1, const string& s2) {
        int h1 = stoi(s1.substr(0, 2));
        int m1 = stoi(s1.substr(3, 2));
        int h2 = stoi(s2.substr(0, 2));
        int m2 = stoi(s2.substr(3, 2));
        return (h2-h1)*60 + (m2-m1);
    }
};

int main() {
    Solution sol = Solution();
//    vector<string> strs = {"23:59", "00:00"};
    vector<string> strs = {"23:57", "23:59", "00:00"};
    int res = sol.findMinDifference(strs);
    cout << res << endl;
    return 0;
}
