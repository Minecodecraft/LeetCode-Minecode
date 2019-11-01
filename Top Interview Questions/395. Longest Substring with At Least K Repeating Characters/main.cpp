//
//  main.cpp
//  395. Longest Substring with At Least K Repeating Characters
//
//  Created by 边俊林 on 2019/10/31.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
    int longestSubstring(string s, int k) {
        int len = (int)s.length();
        int res = 0, l, r;
        for (l = 0; l <= len-k; ) {
            vector<int> cnt (26, 0);
            int mask = 0;
            int nxt = l;
            for (r = l; r < len; ++r) {
                int ch = s[r] - 'a';
                cnt[ch]++;
                if (cnt[ch] >= k)
                    mask &= (~(1 << ch));
                else
                    mask |= (1 << ch);
                
                if (mask == 0) {
                    res = max(res, r - l + 1);
                    nxt = r;
                }
            }
            l = nxt + 1;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "aaabb";
//    string s = "ababbc";
    string s = "";
//    int k = 3;
//    int k = 2;
    int k = 1;
    int res = sol.longestSubstring(s, k);
    cout << res << endl;
    return 0;
}
