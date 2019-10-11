//
//  main.cpp
//  739. Daily Temperatures
//
//  Created by 边俊林 on 2019/10/10.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/daily-temperatures/
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
    using pir = pair<int, int>;
    vector<int> dailyTemperatures(vector<int>& T) {
        auto cmp = [](pir& a, pir& b) {
            return a.first > b.first;
        };
        vector<int> res (T.size(), 0);
        priority_queue<pir, vector<pir>, decltype(cmp)> pq (cmp);
        for (int i = 0; i < T.size(); ++i) {
            int cur = T[i];
            while (pq.size() && pq.top().first < cur) {
                pir pre = pq.top(); pq.pop();
                res[pre.second] = i - pre.second;
            }
            pq.emplace(cur, i);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {
        73, 74, 75, 71, 69, 72, 76, 73
    };
    auto res = sol.dailyTemperatures(arr);
    for_each(res.begin(), res.end(), [](int& elem) { cout << elem << ",";});
    return 0;
}
