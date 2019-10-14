//
//  main.cpp
//  787. Cheapest Flights Within K Stops
//
//  Created by 边俊林 on 2019/10/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/cheapest-flights-within-k-stops/
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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> vexs;
        for (auto& flight: flights)
            vexs[flight[0]].emplace_back(flight[1], flight[2]);
        auto cmp = [](Node& a, Node& b) {
            return a.val > b.val || a.val == b.val && a.k > b.k;
        };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq (cmp);
        vector<bool> vis (n, false);
        pq.emplace(src, 0, 0);
        while (pq.size()) {
            Node cur = pq.top(); pq.pop();
            if (cur.s == dst) return cur.val;

            auto adjs = vexs[cur.s];
            for (auto& adj: adjs) {
                if (cur.k <= K)
                    pq.emplace(adj.first, cur.val+adj.second, cur.k+1);
            }
        }
        return -1;
    }

private:
    struct Node {
        int s;
        int val;
        int k;

        Node(int s, int val, int k)
        : s(s), val(val), k(k) {}
    };
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> flis = {
        {0, 1, 100}, {1, 2, 100}, {0, 2, 500}
//        {0,1,1},{0,2,5},{1,2,1},{2,3,1}
    };
    int res = sol.findCheapestPrice(3, flis, 0, 2, 1);
//    int res = sol.findCheapestPrice(3, flis, 0, 2, 0);
//    int res = sol.findCheapestPrice(4, flis, 0, 3, 1);
    cout << res << endl;
    return 0;
}
