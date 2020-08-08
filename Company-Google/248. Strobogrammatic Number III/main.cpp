//
//  main.cpp
//  248. Strobogrammatic Number III
//
//  Created by Jaylen Bian on 8/7/20.
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

// Solution 1: 228ms, not so good
/*
inline bool cmp(const string& a, const string& b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    int p = 0;
    while (p < a.length()) {
        if (a[p] != b[p])
            return a[p] <= b[p];
        ++p;
    }
    return false;
}

class Solution {
    map<char, char> stro = {
        {'0', '0'}, {'1', '1'},
        {'6', '9'}, {'8', '8'},
        {'9', '6'}
    };
    int nl, nh;

public:
    int strobogrammaticInRange(string low, string high) {
        if (low != high && !cmp(low, high))
            return 0;
        nl = low.length();
        nh = high.length();
        vector<string> res;
        for (int i = nl; i <= nh; ++i)
            recur(i, i, "", "", res);
        auto lit = lower_bound(res.begin(), res.end(), low, cmp);
        auto rit = prev(upper_bound(res.begin(), res.end(), high, cmp));
        return rit - lit + 1;
    }

    void recur(int n, int last, string pre, string suf, vector<string>& res) {
        if (last <= 0) {
            res.emplace_back(pre+suf);
            return;
        }
        for (auto it = stro.begin(); it != stro.end(); ++it) {
            if (n == last && last != 1 && it->first == '0') continue;
            if (last == 1 && it->first == it->second) {
                recur(n, last-1, pre+it->first, suf, res);
            } else if (last >= 2) {
                recur(n, last-2, pre+it->first, it->second+suf, res);
            }
        }
    }
};
 */

// Solution 2: Best, use some Math, 0ms
class Solution {
    vector<pair<char, char>> pir = {
        {'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}
    };

public:
    int strobogrammaticInRange(string low, string high) {
        int l1 = low.length(), l2 = high.length();
        if (l1 > l2 || (l1 == l2 && low > high))
            return 0;
        int res = 0;
        // when len=0 there's only 1 base case, len=1 there's {0, 1, 8} 3 base cases.
        vector<int> tot = {1, 3};
        for (int i = 2; i <= l2-1; ++i) {
            if (i >= l1+1)
                res += tot[i&1] * 4;
            tot[i&1] *= 5;
        }

        // len = low
        string str1 (l1, '0');
        helper(res, 0, l1-1, str1, low, high);

        // len = high
        if (l1 != l2) {
            string str2 (l2, '0');
            helper(res, 0, l2-1, str2, low, high);
        }

        return res;
    }

    void helper(int& res, int l, int r, string& str, string& low, string& high) {
        if (l > r) {
            if ((str.length() > low.length() || str >= low)
                && (str.length() < high.length() || str <= high))
                ++res;
            return;
        }
        // select range of `pir`
        int beg = l == 0 && r != 0 ? 1 : 0;
        int end = l == r ? 2 : 4;
        for (int i = beg; i <= end; ++i) {
            str[l] = pir[i].first;
            str[r] = pir[i].second;
            if (
                (str.length() > low.length() || str.substr(0, l+1) >= low.substr(0, l+1))
                && (str.length() < high.length() || str.substr(0, l+1) <= high.substr(0, l+1))
            ) {
                helper(res, l+1, r-1, str, low, high);
            }
        }
    }
};

int main() {
    Solution sol = Solution();
    string low = "50", high = "100";
    int res = sol.strobogrammaticInRange(low, high);
    cout << res << endl;

    return 0;
}
