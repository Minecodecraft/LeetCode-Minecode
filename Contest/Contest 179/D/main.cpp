//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2020/3/8.
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
private:
    struct Node {
        double dbl;
        int idx;
        int cnt;
    };

public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g = vector<vector<int>> (n+1, vector<int>());
        for (auto& edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis (n+1, false);

        queue<Node> q;
        q.push({1.0, 1, 0});
        while (q.size()) {
            auto node = q.front();
            q.pop();
            vis[node.idx] = true;

            vector<int> tmparr = {};
            for (auto& ele: g[node.idx]) {
                if (!vis[ele]) tmparr.push_back(ele);
            }

            if (node.idx == target) {
                if (node.cnt == t || tmparr.empty())
                    return node.dbl;
                else
                    return 0.0;
            }

            if (node.cnt < t) {
                for (int nxt: tmparr) {
                    q.push({node.dbl / tmparr.size(),
                        nxt,
                        node.cnt+1});
                }
            }
        }
        return 0.0;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> edges = {
//        {1, 2}, {1, 3}, {1, 7},
//        {2, 4}, {2, 6}, {3, 5}
        {2,1},{3,2},{4,2},{5,4},{6,4},{7,3},{8,5},{9,4},{10,4},{11,2},{12,3},{13,4},{14,4},{15,1},{16,4},{17,13},{18,15},{19,15},{20,19},{21,4},{22,2},{23,6},{24,17},{25,1},{26,2},{27,14},{28,26},{29,9},{30,14},{31,5},{32,28},{33,16},{34,24},{35,27},{36,22},{37,4},{38,33},{39,30},{40,9},{41,34},{42,24},{43,38},{44,4},{45,23},{46,8},{47,16},{48,41},{49,41},{50,8},{51,28},{52,10},{53,52},{54,2},{55,24},{56,9},{57,10},{58,19},{59,2},{60,31},{61,41},{62,2},{63,31},{64,5}
    };
//    int n = 7, t = 1, tar = 7;
//    int n = 7, t = 20, tar = 6;
//    int n = 7, t = 2, tar = 4;
    int n = 64, t = 49, tar = 56;
    double res = sol.frogPosition(n, edges, t, tar);
    cout << res << endl;
    return 0;
}
