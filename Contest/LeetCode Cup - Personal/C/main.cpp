//
//  main.cpp
//  C
//
//  Created by Jaylen Bian on 4/18/20.
//  Copyright © 2020 Jaylen Bian. All rights reserved.
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
private:
    class cmp {
    public:
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        }
    };

public:
    vector<int> getTriggerTime(vector<vector<int>>& icrs, vector<vector<int>>& reqs) {
        // c, r, h
        int n = icrs.size(), m = reqs.size();
        vector<int> reqcnt (m, 3);

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> cq, rq, hq;
        for (int i = 0; i < m; ++i) {
            cq.push({reqs[i][0], i});
            rq.push({reqs[i][1], i});
            hq.push({reqs[i][2], i});
        }

        int c = 0, r = 0, h = 0;
        vector<int> res (m, -1);


        for (int i = 0; i <= n; ++i) {
            while (cq.size() && cq.top().first <= c) {
                int idx = cq.top().second;
                if (--reqcnt[idx] == 0)
                    res[idx] = i;
                cq.pop();
            }
            while (rq.size() && rq.top().first <= r) {
                int idx = rq.top().second;
                if (--reqcnt[idx] == 0)
                    res[idx] = i;
                rq.pop();
            }
            while (hq.size() && hq.top().first <= h) {
                int idx = hq.top().second;
                if (--reqcnt[idx] == 0)
                    res[idx] = i;
                hq.pop();
            }


            if (i < n) {
                c += icrs[i][0];
                r += icrs[i][1];
                h += icrs[i][2];
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    increase = [[2,8,4],[2,5,0],[10,9,8]] requirements = [[2,11,3],[15,10,7],[9,17,12],[8,1,14]]
    vector<vector<int>> icrs = {
        {2, 8, 4}, {2, 5, 0}, {10, 9, 8}
    };
    vector<vector<int>> reqs = {
        {2,11,3}, {15,10,7}, {9, 17, 12}, {8, 1, 14}
    };
    auto res = sol.getTriggerTime(icrs, reqs);
    cout << res.size() << endl;
    return 0;
}
