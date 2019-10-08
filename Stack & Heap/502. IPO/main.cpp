//
//  main.cpp
//  502. IPO
//
//  Created by 边俊林 on 2019/10/7.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/ipo/
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
    using pir = pair<int, int>;

    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> doable;
        multiset<pair<int, int>> undoable;

        for (int i = 0; i < Profits.size(); ++i) {
            if (Profits[i] <= 0) continue;
            if (Capital[i] <= W) doable.push(Profits[i]);
            else undoable.emplace(Capital[i], Profits[i]);
        }
        while (k-- && doable.size()) {
            W += doable.top(); doable.pop();
            for (auto it = undoable.begin(); it != undoable.end() && it->first <= W; it = undoable.erase(it))
                doable.push(it->second);
        }
        return W;
    }
};

int main() {
    Solution sol = Solution();
    int k = 2, W = 0;
    vector<int> pro = {
        1, 2, 3
    };
    vector<int> cap = {
        0, 1, 1
    };
    int res = sol.findMaximizedCapital(k, W, pro, cap);
    cout << res << endl;
    return 0;
}
