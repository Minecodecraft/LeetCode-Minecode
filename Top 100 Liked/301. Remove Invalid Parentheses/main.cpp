//
//  main.cpp
//  301. Remove Invalid Parentheses
//
//  Created by 边俊林 on 2019/10/17.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
// Solution 1: DFS, use map and set to save data, not so good, 236ms, beats 8%
/*
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        map<int, unordered_set<string>> res;
        solve(s, 0, "", 0, 0, res);

        if (res.size()) {
            auto st = res.rbegin()->second;
            return vector<string>(st.begin(), st.end());
        }
        return {""};
    }

private:
    void solve(const string& s, int idx, string path, int val, int cnt, map<int, unordered_set<string>>& res) {
        if (idx >= s.length()) {
            if (val == 0 && path.size())
                res[cnt].insert(path);
            return;
        }
        if (s[idx] != '(' && s[idx] != ')') {
            solve(s, idx+1, path+s[idx], val, cnt, res);
            return;
        }

        if (s[idx] == '(' || val > 0)
            solve(s, idx+1,
                  path + s[idx],
                  val + (s[idx]=='(' ? 1 : -1),
                  cnt + (s[idx]==')' ? 1 : 0),
                  res);
        solve(s, idx+1, path, val, cnt, res);
    }
};
 */

// Solution 2: DFS, clearlly code
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        int lToRemove = 0, rToRemove = 0;
        for (char& ch: s) {
            if (ch == '(') {
                ++lToRemove;
            } else if (ch == ')') {
                if (lToRemove > 0) --lToRemove;
                else ++rToRemove;
            }
        }
        solve(s, 0, "", lToRemove, rToRemove, 0, res);
        return vector<string>(res.begin(), res.end());
    }

private:
    void solve(string s, int idx, string path, int lToRemove, int rToRemove, int pairs, unordered_set<string>& res) {
        if (idx == s.length()) {
            if (lToRemove == 0 && rToRemove == 0 && pairs == 0)
                res.insert(path);
            return;
        }
        if (s[idx] != '(' && s[idx] != ')') {
            solve(s, idx+1, path+s[idx], lToRemove, rToRemove, pairs, res);
        } else {
            if (s[idx] == '(') {
                if (lToRemove > 0)
                    solve(s, idx+1, path, lToRemove-1, rToRemove, pairs, res);
                solve(s, idx+1, path+s[idx], lToRemove, rToRemove, pairs+1, res);
            } else if (s[idx] == ')') {
                if (rToRemove > 0)
                    solve(s, idx+1, path, lToRemove, rToRemove-1, pairs, res);
                if (pairs > 0)
                    solve(s, idx+1, path+s[idx], lToRemove, rToRemove, pairs-1, res);
            }
        }
    }
};

int main() {
    Solution sol = Solution();
//    string s = "()())()";
//    string s = "(a)())()";
//    string s = ")(";
    string s = "()())()";
    auto res = sol.removeInvalidParentheses(s);

    for (auto& str: res) {
        cout << str << endl;
    }

    return 0;
}
