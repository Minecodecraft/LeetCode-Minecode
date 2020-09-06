//
//  main.cpp
//  1088. Confusing Number II
//
//  Created by Jaylen Bian on 9/6/20.
//  Copyright © 2020 边俊林. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
    unordered_map<int, int> rev = {
        {0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}
    };
    vector<int> st = {
        0, 1, 6, 8, 9
    };

    void dfs(int idx, int len, bool isPreSame, vector<int>& nele, vector<int>& ele, int& res) {
        if (idx == len) {
            bool isPali = true;
            for (int i = 0; i < ele.size(); ++i) {
                if (rev[ele[i]] != ele[ele.size()-1-i]) {
                    isPali = false;
                    break;
                }
            }
            if (!isPali)
                ++res;
            return;
        }
        for (int i = 0; i < st.size(); ++i) {
            if (st[i] == 0 && idx == 0)
                continue;
            if (isPreSame && nele[idx] < st[i])
                break;
            ele.push_back(st[i]);
            dfs(idx+1, len, isPreSame && nele[idx]==st[i], nele, ele, res);
            ele.pop_back();
        }
    }

public:
    int confusingNumberII(int n) {
        vector<int> nele, ele;
        int tmpn = n, len = 0;
        while (tmpn) {
            nele.push_back(tmpn % 10);
            tmpn /= 10;
            ++len;
        }
        reverse(nele.begin(), nele.end());

        int res = 0;
        for (int i = 1; i <= len; ++i)
            dfs(0, i, i == len, nele, ele, res);
        return res;
    }
};

int main() {
    Solution sol = Solution();
    int n = 20;
    int res = sol.confusingNumberII(n);
    cout << res << endl;
    return 0;
}
