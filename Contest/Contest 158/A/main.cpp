//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2019/10/13.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
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
    int balancedStringSplit(string s) {
        int tot = 0;
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'R') --cnt;
            else if (s[i] == 'L') ++cnt;
            if (cnt == 0) ++tot;
        }
        return tot;
    }
};

int main() {
    Solution sol = Solution();
    string s = "RLLLLRRRLR";
    cout << sol.balancedStringSplit(s) << endl;
    return 0;
}
