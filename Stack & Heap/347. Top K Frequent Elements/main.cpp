//
//  main.cpp
//  347. Top K Frequent Elements
//
//  Created by 边俊林 on 2019/10/4.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/top-k-frequent-elements/
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto &elem: nums) cnt[elem]++;
        vector<pair<int, int>> pir;
        for (auto &kv: cnt)
            pir.push_back(make_pair(kv.second, kv.first));
        sort(pir.begin(), pir.end(), cmp);
        vector<int> res;
        for (int i = 0; i < k; ++i) res.push_back(pir[i].second);
        return res;
    }

private:
    struct cmp {
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first >= b.first;
        }
    } cmp;
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        1, 1, 1, 2, 2, 3
    };
    int k = 2;
    auto res = sol.topKFrequent(nums, k);
    cout << res.size() << endl;
    return 0;
}
