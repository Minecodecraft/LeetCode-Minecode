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

int main() {
    Solution sol = Solution();
    string stamp = "abc", target = "ababc";
//    string stamp = "abca", target = "aabcaca";
    auto res = sol.movesToStamp(stamp, target);
    for_each(begin(res), end(res), [](int ele) { cout << ele << ", "; });
    cout << endl;
    return 0;
}
