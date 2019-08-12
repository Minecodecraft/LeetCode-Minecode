//
//  main.cpp
//  434. Number of Segments in a String
//
//  Created by 边俊林 on 2019/8/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/number-of-segments-in-a-string/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
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
    int countSegments(string s) {
        istringstream is(s);
        int cnt = 0;
        while (is >> s)
            ++cnt;
        return cnt;
    }
};

int main() {
    Solution sol = Solution();
    string s = "Hello, my name is John";
    int res = sol.countSegments(s);
    cout << res << endl;
    return 0;
}
