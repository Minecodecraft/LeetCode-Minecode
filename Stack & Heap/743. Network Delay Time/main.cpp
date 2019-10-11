//
//  main.cpp
//  743. Network Delay Time
//
//  Created by 边俊林 on 2019/10/10.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
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
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<pair<int, int>>> path;
        for (vector<int>& time: times)
            path[time[0]-1].push_back({time[1]-1, time[2]});

        vector<int> dis (N, INT_MAX);
        queue<pair<int, int>> Q;
        dis[K-1] = 0;
        Q.push(make_pair(K-1, 0));
        while (Q.size()) {
            auto cur = Q.front(); Q.pop();

            auto nxts = path[cur.first];
            for (auto& nxt: nxts) {
                if (dis[nxt.first] > cur.second+nxt.second) {
                    dis[nxt.first] = cur.second+nxt.second;
                    Q.push({nxt.first, cur.second+nxt.second});
                }
            }
        }
        int res = INT_MIN;
        for (int i = 0; i < N; ++i)
            res = max(res, dis[i]);
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
        {2,1,1},{2,3,1},{3,4,1}
    };
    int res = sol.networkDelayTime(mat, 4, 2);
    cout << res << endl;
    return 0;
}
