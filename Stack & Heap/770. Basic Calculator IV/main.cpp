//
//  main.cpp
//  770. Basic Calculator IV
//
//  Created by 边俊林 on 2019/10/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/basic-calculator-iv/
\* ------------------------------------------------------ */

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
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        auto& exp = expression;
        ump mapping;
        for (int i = 0; i < evalvars.size(); ++i) mapping[evalvars[i]] = evalints[i];

        int idx = 0;
        ump reslist = solve(exp, mapping, idx);
        vector<pir> respir (reslist.begin(), reslist.end());

        sort(respir.begin(), respir.end(), compator);
        vector<string> res;
        for (auto& elem: respir) {
            if (elem.second == 0) continue;
            res.push_back(to_string(elem.second));
            if (!elem.first.empty()) res.back() += '*' + elem.first;
        }
        return res;
    }

private:
    using ump = unordered_map<string, int>;
    using pir = pair<string, int>;

    static bool compator(pir& a, pir& b) {
        vector<string> lstrs = split(a.first, '*'), rstrs = split(b.first, '*');
        return lstrs.size() > rstrs.size() || lstrs.size()==rstrs.size() && lstrs < rstrs;
    }

    ump solve(string& s, ump& mapping, int& idx) {
        vector<ump> nodes;
        vector<char> ops = {'+'};
        int len = s.length();
        while (idx < len && s[idx] != ')') {
            if (s[idx] == '(') {
                nodes.push_back(solve(s, mapping, ++idx));
            } else {
                int r = idx;
                while (r < len && s[r] != ' ' && s[r] != ')') ++r;
                string curexp = s.substr(idx, r-idx);
                idx = r;
                bool isNumber = true;
                for (char& ch: curexp)
                    if (!isdigit(ch)) { isNumber = false; break; }

                ump tmpnode;
                if (isNumber)
                    tmpnode[""] = stoi(curexp);
                else if (mapping.count(curexp) > 0)
                    tmpnode[""] = mapping[curexp];
                else
                    tmpnode[curexp] = 1;
                nodes.emplace_back(tmpnode);
            }

            if (idx < len && s[idx] == ' ') {
                ops.push_back(s[idx+1]);
                idx += 3;
            }
        }
        idx++;
        return calculate(nodes, ops);
    }

    ump calculate(vector<ump> nodes, vector<char> ops) {
        ump res;
        for (int i = ops.size()-1; i >= 0; --i) {
            ump tmp = nodes[i];
            while (i >= 0 && ops[i] == '*')
                tmp = multiply(tmp, nodes[--i]);
            int sign = ops[i] == '+' ? 1 : -1;
            for (auto& kv: tmp) res[kv.first] += sign * kv.second;
        }
        return res;
    }

    ump multiply(ump& lhs, ump& rhs) {
        ump res;
        for (auto& lele: lhs) {
            for (auto& rele: rhs) {
                string cmbstr = combine(lele.first, rele.first);
                res[cmbstr] += lele.second * rele.second;
            }
        }
        return res;
    }

    string combine(const string& a, const string& b) {
        if (a.empty()) return b;
        if (b.empty()) return a;

        vector<string> strs = split(a, '*');
        for (auto& str: split(b, '*')) strs.emplace_back(str);
        sort(strs.begin(), strs.end());
        string res = "";
        for (auto& str: strs) res += str + '*';
        res.pop_back();
        return res;
    }

    static vector<string> split(const string& s, char ch) {
        stringstream ss (s);
        vector<string> res;
        string tmp;
        while (getline(ss, tmp, ch))
            res.push_back(tmp);
       return res;
    }
};

int main() {
    Solution sol = Solution();
    string exp = "e + 8 - a + 5";
    vector<string> k = {
        "e"
    };
    vector<int> v = {
        1
    };
    auto res = sol.basicCalculatorIV(exp, k, v);
    for_each(res.begin(), res.end(), [](auto& str) { cout << str << endl; });
    return 0;
}
