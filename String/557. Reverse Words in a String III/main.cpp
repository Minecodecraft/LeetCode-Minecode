//
//  main.cpp
//  557. Reverse Words in a String III
//
//  Created by 边俊林 on 2019/8/16.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/reverse-words-in-a-string-iii/
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
    string reverseWords(string s) {
        istringstream ss(s);
        string res = "";
        string tmp;
        while (ss >> tmp) {
            reverse(tmp.begin(), tmp.end());
            if (!res.empty())
                res += " ";
            res += tmp;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    string s = "Let's take LeetCode contest";
    auto res = sol.reverseWords(s);
    cout << res << endl;
    return 0;
}
