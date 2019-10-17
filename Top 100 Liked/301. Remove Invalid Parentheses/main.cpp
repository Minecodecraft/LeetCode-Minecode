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
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        map<int, unordered_set<string>> res;
        solve(s, "", 0, 0, res);

        if (res.size()) {
            auto st = res.rbegin()->second;
            return vector<string>(st.begin(), st.end());
        }
        return {""};
    }

private:
    void solve(string s, string path, int val, int cnt, map<int, unordered_set<string>>& res) {
        if (s.empty()) {
            if (val == 0 && path.size())
                res[cnt].insert(path);
            return;
        }
        if (s.front() != '(' && s.front() != ')') {
            solve(s.substr(1), path+s.front(), val, cnt, res);
            return;
        }

        if (s.front() == '(' || val > 0)
            solve(s.substr(1),
                  path + s.front(),
                  val + (s.front()=='(' ? 1 : -1),
                  cnt + (s.front()==')' ? 1 : 0),
                  res);
        solve(s.substr(1), path, val, cnt, res);
    }
};

int main() {
    Solution sol = Solution();
//    string s = "()())()";
//    string s = "(a)())()";
    string s = ")(";
    auto res = sol.removeInvalidParentheses(s);

    for (auto& str: res) {
        cout << str << endl;
    }

    return 0;
}
