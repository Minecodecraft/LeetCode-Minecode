//
//  main.cpp
//  71. Simplify Path
//
//  Created by 边俊林 on 2019/7/28.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/simplify-path/
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
    string simplifyPath(string path) {
        stack<string> st;
        if (path.length() <= 0) return "";

        string tmp;
        int p = 0;
        while (!path.empty() && path[p] == '/')
            ++p;
        path = path.substr(p);

        while (!path.empty()) {
            p = 0;
            while (p < path.length() && path[p] != '/')
                ++p;
            tmp = path.substr(0, p);

            if (tmp == "..") {
                if (!st.empty()) st.pop();
            } else if (tmp != ".")
                st.push(tmp);

            while (!path.empty() && path[p] == '/')
                ++p;
            path = path.substr(p);
        }

        string res = "/";
        while (!st.empty()) {
            tmp = st.top();
            st.pop();
            tmp += '/';
            res.insert(1, tmp);
        }
        if (res.length() > 1)
            res.erase(res.length()-1);
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string path = "/home/";
//    string path = "/../";
//    string path = "/home//foo/";
//    string path = "/home////foo/.././foo2/../foo3/";
    string path = "///TJbrd/owxdG//";
    auto res = sol.simplifyPath(path);
    cout << res << endl;
    return 0;
}
