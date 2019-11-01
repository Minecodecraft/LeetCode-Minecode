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
// Solution 1: O(n) avg and O(n^2) in worst case, a improvement of brute force
/*
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
 */

// Solution 2: O(n) in avg and worst case, 26 level recursions at most
class Solution {
public:
    int longestSubstring(string s, int k) {
        return getLong(s, k, 0, s.length());
    }
    
private:
    int getLong(const string& s, int k, int l, int r) {
        vector<int> cnt (26, 0);
        for (int i = l; i < r; ++i)
            cnt[s[i]-'a']++;
        
        int res = 0;
        for (; l < r; ) {
            int ll = l;
            while (ll < r && cnt[s[ll]-'a'] < k) ++ll;
            if (ll == r) break;
            int rr = ll;
            while (rr < r && cnt[s[rr]-'a'] >= k) ++rr;
            if (ll == l && rr == r) return r-l;
            res = max(res, getLong(s, k, ll, rr));
            l = rr;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "aaabb";
    string s = "ababbc";
//    string s = "";
//    int k = 3;
    int k = 2;
//    int k = 1;
    int res = sol.longestSubstring(s, k);
    cout << res << endl;
    return 0;
}
