//
//  main.cpp
//  541. Reverse String II
//
//  Created by 边俊林 on 2019/8/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/reverse-string-ii/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
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
    string reverseStr(string s, int k) {
        int idx = 0, n = s.length();
        while (idx < n) {
            int len = min(k, n - idx);
            reverse(s.begin() + idx, s.begin() + idx + len);
            idx += len * 2;
        }
        return s;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "abcdefg";
//    int k = 2;
    string s = "abcdefgh";
    int k = 3;
    auto res = sol.reverseStr(s, k);
    cout << res << endl;
    return 0;
}
