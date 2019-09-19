//
//  main.cpp
//  567. Permutation in String
//
//  Created by 边俊林 on 2019/9/19.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/permutation-in-string
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
    bool checkInclusion(string s1, string s2) {
        string rawHash = hash(s1);
        int len1 = s1.length(), len2 = s2.length();
        if (len1 > len2) return false;

        for (int i = 0; i <= len2-len1; ++i)
            if (rawHash == hash(s2.substr(i, len1)))
                return true;
        return false;
    }

private:
    string hash(const string& str) {
        string hash = "";
        vector<int> cnt (26);
        for (auto ch: str) cnt[ch - 'a']++;
        for (int i = 0; i < 26; ++i) {
            hash += to_string(cnt[i]);
            hash += ",";
        }
        return hash;
    }
};

int main() {
    Solution sol = Solution();
    string s1 = "ab";
    string s2 = "eidboaooo";
    bool res = sol.checkInclusion(s1, s2);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
