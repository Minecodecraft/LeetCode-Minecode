//
//  main.cpp
//  683. K Empty Slots
//
//  Created by 边俊林 on 2019/12/19.
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
// Solution 1: O(nlogn), beats only 30%, not good, no Google
/*
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        map<int, int> mp = {
            {-INF, 0}, {INF, 0}
        };
        for (int i = 0; i < n; ++i) {
            auto it = mp.insert({bulbs[i], i}).first;
            if (it->first - prev(it)->first == k+1 || next(it)->first - it->first == k+1)
                return i+1;
        }
        return -1;
    }

private:
    const int INF = 0x3f3f3f3f;
};
 */

// Solution 2: O(n), beats 60% +
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        vector<int> d (n, 0);
        for (int i = 0; i < n; ++i)
            d[bulbs[i]-1] = i+1;
        int l = 0, r = k+1, res = INT_MAX;
        for (int i = 0; i < n && r < n; ++i) {
            if (i == r)
                res = min(res, max(d[l], d[r]));
            if (d[l] > d[i] || d[r] >= d[i]) {
                l = i;
                r = i + k + 1;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> blubs = {
        1, 3, 2
    };
    int k = 1;
    int res = sol.kEmptySlots(blubs, k);
    cout << res << endl;
    return 0;
}
