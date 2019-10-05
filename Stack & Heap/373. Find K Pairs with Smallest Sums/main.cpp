//
//  main.cpp
//  373. Find K Pairs with Smallest Sums
//
//  Created by 边俊林 on 2019/10/5.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<Comb> combs;
        for (int i = 0; i < n1; ++i)
            for (int j = 0; j < n2; ++j)
                combs.push_back(Comb(nums1[i]+nums2[j], nums1[i], nums2[j]));
        auto cmp = [] (Comb& a, Comb& b) {
            if (a.sum == b.sum) return a.first <= b.first;
            return a.sum <= b.sum;
        };
        int resSz = min(n1*n2, k);
        partial_sort(combs.begin(), combs.begin()+resSz, combs.end(), cmp);
        vector<vector<int>> res (resSz);
        for (int i = 0; i < resSz; ++i)
            res[i] = {combs[i].first, combs[i].second};
        return res;
    }

private:
    struct Comb {
        int sum;
        int first;
        int second;

        Comb(int sum, int first, int second)
        : sum(sum), first(first), second(second) { }
    };
};

int main() {
    Solution sol = Solution();
//    vector<int> nums1 = {1, 7, 11};
//    vector<int> nums2 = {2, 4, 6};
//    int k = 3;
    vector<int> nums1 = {};
    vector<int> nums2 = {};
    int k = 3;
    auto res = sol.kSmallestPairs(nums1, nums2, k);
    cout << res.size() << endl;
    return 0;
}
