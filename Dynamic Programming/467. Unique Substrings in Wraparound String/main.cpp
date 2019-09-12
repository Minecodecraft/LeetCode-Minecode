//
//  main.cpp
//  467. Unique Substrings in Wraparound String
//
//  Created by 边俊林 on 2019/9/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/unique-substrings-in-wraparound-string/
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
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt (26);
        int tmp = 0;
        for (int i = 0; i < p.length(); ++i) {
            int idx = p[i] - 'a';
            if (i > 0 && (p[i-1]-'a') != (idx+25)%26)
                tmp = 0;
            cnt[idx] = max(cnt[idx], ++tmp);
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};

int main() {
    Solution sol = Solution();
//    string p = "a";
//    string p = "cac";
//    string p = "zab";
//    string p = "";
//    string p = "zaba";
    string p = "uvwxyzabcdefg";
    int res = sol.findSubstringInWraproundString(p);
    cout << res << endl;
    return 0;
}
