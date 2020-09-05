//
//  main.cpp
//  1096. Brace Expansion II
//
//  Created by Jaylen Bian on 9/4/20.
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
    string getWord(string& s, int& p) {
        string res = "";
        while (p < s.length() && islower(s[p]))
            res.push_back(s[p++]);
        return res;
    }

    unordered_set<string> dfs(string exp, int& p) {
        unordered_set<string> res, pretmp;
        while (p < exp.length() && exp[p] != '}') {
            if (exp[p] == ',') {
                for (auto& ele: pretmp)
                    res.insert(ele);
                pretmp.clear();
                ++p;
            }

            unordered_set<string> suftmp;
            if (exp[p] == '{') {
                ++p;
                suftmp = dfs(exp, p);
                ++p;
            } else {
                suftmp.insert(getWord(exp, p));
            }

            if (pretmp.empty()) {
                pretmp = suftmp;
            } else {
                unordered_set<string> tmp;
                for (auto& pre: pretmp)
                    for (auto& suf: suftmp)
                        tmp.insert(pre + suf);
                pretmp = tmp;
            }
        }
        for (auto& pre: pretmp)
            res.insert(pre);
        return res;
    }
public:
    vector<string> braceExpansionII(string exp) {
        int p = 0;
        auto st = dfs(exp, p);
        auto res = vector<string>(st.begin(), st.end());
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol = Solution();
    string s = "{a,b}{c,{d,e}}";
    auto res = sol.braceExpansionII(s);
    cout << "[";
    for (auto& ele: res) {
        cout << ele << ",";
    }
    cout << "]" << endl;
    return 0;
}
