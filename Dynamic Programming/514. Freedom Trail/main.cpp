//
//  main.cpp
//  514. Freedom Trail
//
//  Created by 边俊林 on 2019/9/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/freedom-trail/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
// Solution 1: DFS with memorization, 148ms
/*
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        return countStep(ring, 0, key) + key.length();
    }

private:
    unordered_map<string, int> _hash;

    int countStep(const string& ring, int ringidx, string key) {
        if (key.empty()) return 0;
        int len = ring.length();

        string hashKey = to_string(ringidx) + "-" + key;
        if (_hash.count(hashKey) > 0)
            return _hash[hashKey];

        int l = ringidx, r = ringidx;
        int lcnt = 0, rcnt = 0;
        l = mod(l, len);
        r = mod(r, len);
        while (key[0] != ring[l]) {
            l = mod(l-1, len);
            ++lcnt;
        }
        while (key[0] != ring[r]) {
            r = mod(r+1, len);
            ++rcnt;
        }

        int res = countStep(ring, l, key.substr(1)) + lcnt;
        if (l != r || lcnt != rcnt) {
            res = min(res, countStep(ring, r, key.substr(1)) + rcnt);
        }
        return _hash[hashKey] = res;
    }

    int mod(int a, int b) {
        return (a % b + b) % b;
    }
};
 */

// Solution 2: DP with dimensionality reduction, 20ms
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int lenk = key.length(), lenr = ring.length();
        vector<int> cur (lenr, INT_MAX);
        vector<int> pre (lenr, INT_MAX);
        vector<vector<int>> mp (26);
        for (int i = 0; i < lenr; ++i)
            mp[ring[i] - 'a'].push_back(i);

        vector<int> startidx = {0};
        pre[0] = 0;
        for (int i = 0; i < lenk; ++i) {
            auto desArr = mp[key[i] - 'a'];
            fill(cur.begin(), cur.end(), INT_MAX);
            for (int j = 0; j < desArr.size(); ++j) {
                for (int k = 0; k < startidx.size(); ++k) {
                    int minDist = min(
                                      (startidx[k] - desArr[j] + lenr) % lenr,
                                      (desArr[j] - startidx[k] + lenr) % lenr
                                      ) + pre[startidx[k]];
                    cur[desArr[j]] = min(cur[desArr[j]], minDist);
                }
            }
            startidx = desArr;
            swap(cur, pre);
        }
        return *min_element(pre.begin(), pre.end()) + lenk;
    }
};

int main() {
    Solution sol = Solution();
    string ring = "godding";
    string key = "gd";
//    string ring = "abcde";
//    string key = "ade";
    int res = sol.findRotateSteps(ring, key);
    cout << res << endl;
    return 0;
}
