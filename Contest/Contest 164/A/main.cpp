//
//  main.cpp
//  Contest 164
//
//  Created by 边俊林 on 2019/11/24.
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
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sz  = points.size();
        int res = 0;
        if (sz == 0) return 0;

        int x = points[0][0], y = points[0][1];

        for (int i = 1; i < sz; ++i) {
            int curx = points[i][0], cury = points[i][1];
            int difa = abs(curx-x), difb = abs(cury-y);
            res += max(difa, difb);
            x = curx;
            y = cury;
        }

        return res;
    }
};

int main() {
    Solution sol =
    
    return 0;
}
