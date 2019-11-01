//
//  main.cpp
//  452. Minimum Number of Arrows to Burst Balloons
//
//  Created by 边俊林 on 2019/11/1.
//  Copyright © 2019 边俊林. All rights reserved.
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
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[1]>b[1] || a[1]==b[1] && a[0]>b[0];
        });
        int n = points.size(), cnt = 0;
        long front = (long)INT_MAX + 1;
        vector<bool> boomb (n, false);
        int i, j;
        for (i = 0; i < n;) {
            if (boomb[i]) continue;
            auto& pir = points[i];
            int tar = pir[0];
            for (j = i; j < n; ++j) {
                if (points[j][1] < tar) break;
                if (points[j][0]<=tar && points[j][1]>=tar)
                    boomb[j] = true;
            }
            ++cnt;
            i = j;
        }
        return cnt;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
//        {10,16}, {2,8}, {1,6}, {7,12}
        {-1,1},{0,1},{2,3},{1,2}
    };
    int res = sol.findMinArrowShots(mat);
    cout << res << endl;
    return 0;
}
