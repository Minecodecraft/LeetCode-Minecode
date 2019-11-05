//
//  main.cpp
//  936. Stamping The Sequence
//
//  Created by 边俊林 on 2019/11/5.
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
// Solution 1: Generate string everytime, not so good, 500ms only beats 26%
/*
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int totcnt = 0, curcnt = INT_MAX;
        int len = stamp.length();
        while (curcnt) {
            curcnt = 0;
            for (int slen = len; slen > 0; --slen) {
                for (int beg = 0; beg <= len-slen; ++beg) {
                    string curstm = string(beg, '*') + stamp.substr(beg, slen) + string(len-slen-beg, '*');
                    auto match = target.find(curstm);
                    while (match != string::npos) {
                        res.push_back(match);
                        fill(begin(target)+match, begin(target)+match+len, '*');
                        curcnt += slen;
                        match = target.find(curstm);
                    }
                }
            }
            totcnt += curcnt;
        }
        reverse(begin(res), end(res));
        return totcnt == target.length() ? res : vector<int>();
    }
};
 */

// Solution 2: Simple Recursive, 76ms, beats 70%
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> path;
        string done = string(target.size(), '*');
        string cur = target;
        while (cur != done) {
            int idx = remove(stamp, cur);
            if (idx == target.length())
                return vector<int>();
            path.push_back(idx);
        }
        reverse(begin(path), end(path));
        return path;
    }

private:
    int remove(string& stamp, string& target) {
        for (int i = 0; i < target.length(); ++i) {
            int tarp = 0, stmp = 0;
            bool changed = false;
            while (stmp < stamp.length() && tarp < target.length() && (target[i+tarp] == stamp[stmp] || target[i+tarp] == '*')) {
                if (target[i+tarp] == stamp[stmp])
                    changed = true;
                ++tarp;
                ++stmp;
            }
            if (stmp == stamp.length() && changed) {
                fill(begin(target) + i, begin(target) + i + stamp.size(), '*');
                return i;
            }
        }
        return target.length();
    }
};

int main() {
    Solution sol = Solution();
//    string stamp = "abc", target = "ababc";
    string stamp = "abca", target = "aabcaca";
    auto res = sol.movesToStamp(stamp, target);
    for_each(begin(res), end(res), [](int ele) { cout << ele << ", "; });
    cout << endl;
    return 0;
}
