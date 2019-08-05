//
//  main.cpp
//  165. Compare Version Numbers
//
//  Created by 边俊林 on 2019/8/5.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/compare-version-numbers/
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
    int compareVersion(string version1, string version2) {
        auto la = version1.length(), lb = version2.length();
        int l1, l2, r1, r2, a, b;
        l1 = l2 = r1 = r2 = a = b = 0;
        while (l1 < la || l2 < lb) {
            a = b = 0;
            while (r1 < la && version1[r1] != '.') ++r1;
            while (r2 < lb && version2[r2] != '.') ++r2;
            a = r1 <= la ? stoi(version1.substr(l1, r1-l1)) : 0;
            b = r2 <= lb ? stoi(version2.substr(l2, r2-l2)) : 0;
            if (a != b)
                return a < b ? -1 : 1;
            l1 = ++r1;
            l2 = ++r2;
        }
        return a < b ? -1 : a == b ? 0 : 1;
    }
};

int main() {
    Solution sol = Solution();
//    string v1 = "0.1";
//    string v2 = "1.1";
//    string v1 = "1.0.1";
//    string v2 = "1";
//    string v1 = "1.01";
//    string v2 = "1.001";
//    string v1 = "1.0";
//    string v2 = "1.0.0";
//    string v1 = "1.0";
//    string v2 = "13.37";
    string v1 = "1";
    string v2 = "0";
    auto res = sol.compareVersion(v1, v2);
    cout << res << endl;
    return 0;
}
