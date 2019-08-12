//
//  main.cpp
//  443. String Compression
//
//  Created by 边俊林 on 2019/8/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/string-compression/
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
    int compress(vector<char>& chars) {
        int l, r, cnt;
        l = r = 0;
        while (r < chars.size()) {
            chars[l] = chars[r];
            cnt = 0;
            while (r < chars.size() && chars[r] == chars[l]) {
                ++cnt;
                ++r;
            }
            if (cnt == 1) {
                ++l;
            } else {
                string cntstr = to_string(cnt);
                ++l;
                for (auto ch: cntstr) {
                    chars[l++] = ch;
                }
            }
        }
        return l;
    }
};

int main() {
    Solution sol = Solution();
//    vector<char> chars = {'a','a','b','b','c','c','c'};
    vector<char> chars = {'a'};
    int res = sol.compress(chars);
    cout << res << endl;
    return 0;
}
