//
//  main.cpp
//  22. Generate Parentheses
//
//  Created by 边俊林 on 2019/7/16.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/generate-parentheses/
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
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        vector<string> res;
        int pre = 0;
        string path = "";
        generateCore(n, 0, pre, path, res);
        return res;
    }

private:
    void generateCore(int n, int cnt, int pre, string& path, vector<string>& res) {
        if (n <= cnt) {
            res.push_back(path);
            return;
        }
        if (pre == 0 || cnt+pre < n) {
            path.push_back('(');
            generateCore(n, cnt, pre+1, path, res);
            path.pop_back();
        }
        if (pre > 0) {
            path.push_back(')');
            generateCore(n, cnt+1, pre-1, path, res);
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
    int n = 3;
    auto res = sol.generateParenthesis(n);
    printVector(res);
    return 0;
}
