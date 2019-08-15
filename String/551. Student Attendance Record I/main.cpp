//
//  main.cpp
//  551. Student Attendance Record I
//
//  Created by 边俊林 on 2019/8/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/student-attendance-record-i/
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
    bool checkRecord(string s) {
        int cnta, cntl;
        cnta = cntl = 0;
        for (auto ch: s) {
            if (ch == 'A') cnta++;
            if (ch == 'L') cntl++;
            else cntl = 0;

            if (cnta > 1 || cntl > 2)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "PPALLP";
//    string s = "PPALLL";
    string s = "LALL";
    bool res = sol.checkRecord(s);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
