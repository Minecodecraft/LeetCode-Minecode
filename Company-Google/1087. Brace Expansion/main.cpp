//
//  main.cpp
//  1087. Brace Expansion
//
//  Created by Jaylen Bian on 8/28/20.
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
    void dfs(vector<vector<char>>& list, vector<string> &res, string& s, int idx) {
        if (idx == list.size()) {
            res.push_back(s);
            return;
        }
        for (int i = 0; i < list[idx].size(); ++i) {
            s += list[idx][i];
            dfs(list, res, s, idx+1);
            s.pop_back();
        }
    }
public:
    vector<string> expand(string s) {
        int p = 0, len = s.length();
        vector<vector<char>> list;
        while (p < len) {
            vector<char> tmp;
            if (s[p] == '{') {
                while (p < len && s[p] != '}') {
                    if (!isalpha(s[p])) ++p;
                    else tmp.push_back(s[p++]);
                }
                ++p;
            } else {
                tmp.push_back(s[p++]);
            }
            sort(tmp.begin(), tmp.end());
            list.push_back(tmp);
        }
        vector<string> res;
        string tmps = "";
        dfs(list, res, tmps, 0);
        return res;
    }
};

int main() {

    return 0;
}
