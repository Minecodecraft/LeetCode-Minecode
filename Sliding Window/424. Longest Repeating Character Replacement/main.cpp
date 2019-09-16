//
//  main.cpp
//  424. Longest Repeating Character Replacement
//
//  Created by 边俊林 on 2019/9/16.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/longest-repeating-character-replacement/
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
    int characterReplacement(string s, int k) {
        vector<int> cnt (26);
        int l = 0, r = 0, res = 0;
        while (r < s.length()) {
            cnt[s[r++]-'A']++;
            if (r-l - *max_element(cnt.begin(), cnt.end()) > k)
                cnt[s[l++]-'A']--;
            res = max(res, r-l);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "ABAB";
//    string s = "ABABA";
    string s = "AABABBA";
    int k = 1;
//    int k = 2;
    int res = sol.characterReplacement(s, k);
    cout << res << endl;
    return 0;
}
