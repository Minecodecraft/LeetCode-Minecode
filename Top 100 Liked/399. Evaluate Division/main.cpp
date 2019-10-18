//
//  main.cpp
//  399. Evaluate Division
//
//  Created by 边俊林 on 2019/10/18.
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
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0], b = equations[i][1];
            hash[a].emplace(b, values[i]);
            hash[b].emplace(a, 1 / values[i]);
        }
        unordered_set<string> vis;
        vector<double> anss;
        for (int i = 0; i < queries.size(); ++i) {
            double res = -1.0;
            vis.clear();
            search(queries[i][0], queries[i][1], 1.0, vis, res);
            anss.push_back(res);
        }
        return anss;
    }

private:
    unordered_map<string, unordered_map<string, double>> hash;

    void search(string a, string b, double fac, unordered_set<string>& vis, double& res) {
        if (hash.count(a) <= 0) return;

        if (hash[a].count(b) > 0) {
            res = hash[a][b] * fac;
            return;
        }
        auto nxtmap = hash[a];
        for (auto it = nxtmap.begin(); it != nxtmap.end(); ++it) {
            if (vis.count(it->first) > 0) continue;
            vis.insert(it->first);
            search(it->first, b, it->second * fac, vis, res);
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<string>> equ = {
        {"a", "b"}, {"b", "c"}
    };
    vector<double> val = {
        2.0, 3.0
    };
    vector<vector<string>> qry = {
        {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}
    };
    vector<double> res = sol.calcEquation(equ, val, qry);
    cout << res.size() << endl;
    return 0;
}
