//
//  main.cpp
//  753. Cracking the Safe
//
//  Created by Jaylen Bian on 7/9/20.
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
public:
    string crackSafe(int n, int k) {
        string prefix = string(n-1, '0');
        res = "";
        dfs(prefix, k);
        res += prefix;
        return res;
    }

private:
    set<string> vis;
    string res;

    void dfs(string prefix, int k) {
        for (int i = 0; i < k; ++i) {
            char ch = i + '0';
            string str = prefix + ch;
            if (!vis.count(str)) {
                vis.insert(str);
                dfs(str.substr(1), k);
                res += ch;
            }
        }
    }
};

int main() {
    Solution sol = Solution();
    auto res = sol.crackSafe(2, 2);
    cout << res << endl;
    return 0;
}
