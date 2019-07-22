//
//  main.cpp
//  38. Count and Say
//
//  Created by 边俊林 on 2019/7/19.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/count-and-say/
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
    string countAndSay(int n) {
        if (n == 0) return "";
        if (n == 1) return "1";
        string res = "1", cur = "";
        int count;
        for (int j = 2; j <= n; ++j) {
            cur = "";
            for (int i = 0; i < res.length(); ++i) {
                count = 1;
                while (i + 1 < res.length() && res[i] == res[i+1]) {
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    int n = 1;
//    auto res = sol.countAndSay(n);
//    cout << res << endl;
    for (int i = 1; i <= 30; ++i) {
        cout << sol.countAndSay(i) << endl;
    }
    return 0;
}
