//
//  main.cpp
//  846. Hand of Straights
//
//  Created by Jaylen Bian on 12/18/20.
//  Copyright © 2020 边俊林. All rights reserved.
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
// Solution 1: So complexity, need to be more concise
/**
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W)
            return false;
        map<int, int> mp;
        for (int ele: hand)
            mp[ele]++;
        if (mp.size() < W)
            return false;
        auto it = mp.begin();
        for (; it != prev(mp.end(), W-1); ++it) {
            if (it->second == 0)
                continue;
            auto nit = next(it);
            int pre = it->first;
            for (int i = 1; i < W; ++i) {
                if (nit->second < it->second || nit->first - pre > 1)
                    return false;
                nit->second -= it->second;
                pre = nit->first;
                nit++;
            }
            it->second = 0;
        }
        while (it != mp.end()) {
            if (it->second)
                return false;
            ++it;
        }
        return true;
    }
};
 */

// Solution 2: Consise solution
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> mp;
        for (int ele: hand)
            mp[ele]++;
        for (auto kv: mp)
            if (kv.second)
                for (int i = W-1; i >= 0; --i)
                    if ((mp[kv.first + i] -= mp[kv.first]) < 0)
                        return false;
        return true;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {
//        1,2,3,6,2,3,4,7,8
        8, 10, 12
    };
    int W = 3;
    bool res = sol.isNStraightHand(arr, W);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
