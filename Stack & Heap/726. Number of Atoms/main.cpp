//
//  main.cpp
//  726. Number of Atoms
//
//  Created by 边俊林 on 2019/10/9.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/number-of-atoms/
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
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<Node> st;
        int l = 0, r = l;
        while (l < formula.length()) {
            r = l;
            if (formula[r] == '(') {
                st.push(Node({}, true));
                ++r;
            } else if (isupper(formula[r])) {
                ++r;
                while (r < formula.length() && islower(formula[r])) ++r;
                t_ump tmp = t_ump();
                tmp[formula.substr(l, r-l)] = 1;
                st.push(Node(tmp, false));
            } else if (formula[r] == ')') {
                t_ump mp = t_ump();
                while (st.top().isLeftBra == false) {
                    Node pNode = st.top(); st.pop();
                    t_ump curmp = pNode.mp;
                    for (auto it = curmp.begin(); it != curmp.end(); ++it)
                        mp[it->first] += it->second;
                }
                st.pop();
                st.push(Node(mp, false));
                ++r;
            } else if (isdigit(formula[r])) {
                while (r < formula.length() && isdigit(formula[r])) ++r;
                int multiplier = stoi(formula.substr(l, r-l));
                Node pNode = st.top(); st.pop();
                t_ump curmp = pNode.mp;
                for (auto it = curmp.begin(); it != curmp.end(); ++it)
                    it->second *= multiplier;
                st.push(Node(curmp, false));
            }
            l = r;
        }
        map<string, int, less<string>> mapping;
        while (st.size()) {
            Node pNode = st.top(); st.pop();
            t_ump curmp = pNode.mp;
            for (auto it = curmp.begin(); it != curmp.end(); ++it)
                mapping[it->first] += it->second;
        }
        string res = "";
        for (auto& kv: mapping) {
            res += kv.first;
            if (kv.second > 1)
                res += to_string(kv.second);
        }
        return res;
    }

private:
    using t_ump = unordered_map<string, int>;
    struct Node {
        t_ump mp;
        bool isLeftBra = false;

        Node(t_ump mp, bool isLeftBra)
        : mp(mp), isLeftBra(isLeftBra) { }
    };
};

int main() {
    Solution sol = Solution();
//    string formula = "H2O";
    string formula = "Mg(OH)2";
//    string formula = "K4(ON(SO3)2)2";
    string res = sol.countOfAtoms(formula);
    cout << res << endl;
    return 0;
}
