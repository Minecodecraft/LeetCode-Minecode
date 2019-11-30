//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/11/30.
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
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int l = toBeRemoved[0], r = toBeRemoved[1];
        auto sit = upper_bound(intervals.begin(), intervals.end(),
                               vector<int> {r, l},
                               [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        auto eit = upper_bound(intervals.begin(), intervals.end(),
                               vector<int> {r, l},
                               [](auto& a, auto& b) {
            return a[0] < b[0];
        });
        
        for (auto it = sit; it != eit && it != intervals.end(); ) {
            int cl = (*it)[0], cr = (*it)[1];
            if (cr <= l || cl > r) {
                ++it;
                continue;
            } else if (cl >= l && cr <= r) { // delete
                it = intervals.erase(it);
            } else {
                if (l > cl && r < cr) {
                    *it = {cl, l};
                    it = intervals.insert(++it, {r, cr});
                } else if (l <= cl && r < cr) {
                    *it = {r, cr};
                } else if (l > cl && l <= cr) {
                    *it = {cl, l};
                }
                ++it;
            }
        }
        return intervals;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> ins = {
//        {0,2}, {3,4}, {5,7}
        {0,2}, {3,5}
//        {0, 5}
    };
//    vector<int> tob = {1, 6};
    vector<int> tob = {2, 3};
    auto res = sol.removeInterval(ins, tob);
    for (auto& arr: res) {
        cout << arr[0] << ", " << arr[1] << endl;
    }
    return 0;
}
