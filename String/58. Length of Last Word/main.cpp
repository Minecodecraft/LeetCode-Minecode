//
//  main.cpp
//  58. Length of Last Word
//
//  Created by 边俊林 on 2019/7/25.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/length-of-last-word/
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
    int lengthOfLastWord(string s) {
        if (s.length() <= 0) return 0;
        int l, r;
        l = r = (s.length() - 1);
        while (r >= 0 && !isalpha(s[r])) --r;
        l = r;
        while (l >= 0) {
            if (isalpha(s[l])) --l;
            else break;
        }
        return r - l;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "Hello World";
//    string s = " World";
    string s = "World   ";
    auto res = sol.lengthOfLastWord(s);
    cout << res << endl;
    return 0;
}
