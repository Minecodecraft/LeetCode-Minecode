//
//  main.cpp
//  207. Course Schedule
//
//  Created by 边俊林 on 2019/10/17.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> reqs (numCourses);
        unordered_map<int, int> reqcnt;
        for (auto& req: prerequisites) {
            reqs[req[1]].insert(req[0]);
            reqcnt[req[0]]++;
        }

        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < numCourses; ++i)
            if (reqcnt[i] == 0) q.push(i);

        while (q.size()) {
            int idx = q.front(); q.pop();
            ++cnt;
            for (auto& elem: reqs[idx]) {
                if (--reqcnt[elem] == 0)
                    q.push(elem);
            }
        }
        return cnt == numCourses;
    }
};

int main() {
    Solution sol = Solution();
    int n = 2;
    vector<vector<int>> reqs = {
//        {1, 0}
        {1, 0}, {0, 1}
    };
    bool res = sol.canFinish(n, reqs);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
