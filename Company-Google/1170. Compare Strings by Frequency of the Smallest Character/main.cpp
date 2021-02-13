//
//  main.cpp
//  1170. Compare Strings by Frequency of the Smallest Character
//
//  Created by Jaylen Bian on 2/13/21.
//  Copyright © 2021 边俊林. All rights reserved.
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
// Solution 1: Use binary search
/*
class Solution {
    int helper(string& str) {
        vector<int> cnt (26, 0);
        for (char ch: str)
            cnt[ch-'a']++;
        for (int ele: cnt)
            if (ele) return ele;
        return 0;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& qs, vector<string>& ws) {
        int m = qs.size(), n = ws.size();
        vector<int> vals (n, 0);
        for (int i = 0; i < n; ++i)
            vals[i] = helper(ws[i]);
        sort(vals.begin(), vals.end());

        vector<int> res (m, 0);
        for (int i = 0; i < m; ++i) {
            int f = helper(qs[i]);
            res[i] = vals.end() - upper_bound(vals.begin(), vals.end(), f);
        }
        return res;
    }
};
 */

// Solution 2
class Solution {
    int calF(string s) {
        vector<int> cnt (26, 0);
        for (char ch: s)
            cnt[ch-'a']++;
        for (int ele: cnt)
            if (ele) return ele;
        return 0;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& qs, vector<string>& ws) {
        vector<int> f (12, 0);
        for (int i = 0; i < ws.size(); ++i) {
            int curf = calF(ws[i]);
            f[curf]++;
        }
        for (int i = 9; i >= 0; --i)
            f[i] += f[i+1];

        vector<int> res;
        for (int i = 0; i < qs.size(); ++i) {
            int curf = calF(qs[i]);
            res.push_back(f[curf+1]);
        }
        return res;
    }
};

int main() {

    return 0;
}
