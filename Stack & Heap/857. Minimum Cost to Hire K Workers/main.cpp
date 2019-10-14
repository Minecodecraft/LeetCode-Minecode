//
//  main.cpp
//  857. Minimum Cost to Hire K Workers
//
//  Created by 边俊林 on 2019/10/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
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
    using pii = pair<int, double>;
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        auto cmp = [](pii& a, pii& b) {
            return a.second < b.second;
        };
        int sz = quality.size();
        vector<pii> vec;
        for (int i = 0; i < sz; ++i)
            vec.emplace_back(quality[i], (double) wage[i] / quality[i]);
        sort(vec.begin(), vec.end(), cmp);
        priority_queue<int> pq;

        int sum = 0;
        for (int i = 0; i < K; ++i) {
            sum += vec[i].first;
            pq.emplace(vec[i].first);
        }
        double res = vec[K-1].second * sum;
        for (int i = K; i < sz; ++i) {
            pq.emplace(vec[i].first);
            sum += vec[i].first;
            sum -= pq.top();
            pq.pop();
            res = min(res, vec[i].second * sum);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> q = {
//        10, 20, 5
        3,1,10,10,1
    };
    vector<int> w = {
//        70, 50, 30
        4,8,2,2,7
    };
//    int k = 2;
    int k = 3;
    double res = sol.mincostToHireWorkers(q, w, k);
    cout << res << endl;
    return 0;
}
