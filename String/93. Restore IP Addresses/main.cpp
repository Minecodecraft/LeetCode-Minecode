//
//  main.cpp
//  93. Restore IP Addresses
//
//  Created by 边俊林 on 2019/7/30.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/restore-ip-addresses/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <cmath>
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
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> path;
        restoreIPCore(s, 0, path, res);
        return res;
    }

private:
    void restoreIPCore(string& s, int idx, vector<string>& path, vector<string>& res) {
        auto level = path.size();
        if (level == 4) {
            if (idx != s.length()) return;
            string str;
            for (int i = 0; i < 4; ++i) {
                str += path[i];
                if (i < 3) str.push_back('.');
            }
            res.push_back(str);
            return;
        }
        if (idx == s.length()) return;
        if (s.length()-idx > (4-level)*3) return;
        for (int i = 1; i <= 3 && idx+i <= s.length(); ++i) {
            string subStr = s.substr(idx, i);
            int value = stoi(subStr);
            if (value > 255) break;
            if (subStr[0] == '0' && i > 1) continue; // 0xx 00x不考虑
            path.push_back(subStr);
            restoreIPCore(s, idx+i, path, res);
            path.pop_back();
        }
    }
};

void printVector(vector<string> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << (it==v.begin() ? '\0' : ' ') << *it << endl;
    }
    printf("]\n");
}


int main() {
    Solution sol = Solution();
//    string s = "25525511135";
//    string s = "255250135";
    string s = "010010";
    auto res = sol.restoreIpAddresses(s);
    printVector(res);
    return 0;
}
