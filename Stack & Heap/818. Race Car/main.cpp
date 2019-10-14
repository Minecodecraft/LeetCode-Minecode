//
//  main.cpp
//  818. Race Car
//
//  Created by 边俊林 on 2019/10/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/race-car/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>tan
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
// Solution 1: BFS Solution with purning
class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q;
        unordered_set<pair<int, int>, set_hash> vis;
        q.emplace(0, 1);
        vis.insert(q.front());
        for (int step = 0; ; ++step) {
            for (int cnt = q.size(); cnt; cnt--) {
                pair<int, int> cur = q.front(); q.pop();

                if (cur.first == target) return step;

                auto nxtPir = make_pair(cur.first+cur.second, cur.second*2);
                if (!vis.count(nxtPir) && abs(nxtPir.first - target) < target) {
                    q.emplace(nxtPir);
                    vis.emplace(nxtPir);
                }

                auto reversePir = make_pair(cur.first, cur.second>0 ? -1 : 1);
                if (!vis.count(reversePir)) {
                    q.emplace(reversePir);
                    vis.emplace(reversePir);
                }
            }
        }
        return 0;
    }

private:
    struct set_hash {
        size_t operator() (const pair<int, int>& elem) const {
            return size_t(elem.first) * size_t(1e5+10) + elem.second;
        }
    };
};

int main() {
    Solution sol = Solution();
    int n = 3;
//    int n = 6;
    int res = sol.racecar(n);
    cout << res << endl;
    return 0;
}
