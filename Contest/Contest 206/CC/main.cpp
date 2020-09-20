//
//  main.cpp
//  C
//
//  Created by Jaylen Bian on 9/19/20.
//  Copyright © 2020 Jaylen Bian. All rights reserved.
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
// Solution 1: Kruskal
/*
class Solution {
    vector<int> f;
    vector<int> rank;
    int sz;

    void UnionFind(int n) {
        f = vector<int> (n);
        rank = vector<int> (n, 1);
        for (int i = 0; i < n; ++i)
            f[i] = i;
        sz = n;
    }

    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv)
            return false;
        if (rank[pu] < rank[pv]) {
            f[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            f[pv] = pu;
        } else {
            f[pu] = pv;
            rank[pv]++;
        }
        --sz;
        return true;
    }

    int Find(int u) {
        if (f[u] != u) f[u] = Find(f[u]);
        return f[u];
    }

    struct Edge {
        int from;
        int to;
        int val;

        Edge(int from, int to, int val) {
            this->from = from;
            this->to = to;
            this->val = val;
        }
    };

public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int n = pts.size();
        UnionFind(n);

        auto cmp = [] (Edge& l, Edge& r) {
            return l.val >= r.val;
        };
        vector<Edge> arr;
        vector<vector<int>> g = vector<vector<int>> (n, vector<int>());
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int dis = abs(pts[i][0]-pts[j][0]) + abs(pts[i][1]-pts[j][1]);
                arr.push_back(Edge(i, j, dis));
            }
        }
        make_heap(arr.begin(), arr.end(), cmp);

        int res = 0;
        while (sz > 1 && arr.size()) {
            pop_heap(arr.begin(), arr.end(), cmp);
            Edge e = arr.back(); arr.pop_back();
            if (Union(e.from, e.to)) {
                res += e.val;
            }
        }
        return res;
    }
};
 */

// Solution 2: Prim
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int n = pts.size(), idx = 0, finish = 0, res = 0;
        vector<bool> vis (n, false);
        priority_queue<pair<int, int>> pq;
        while (++finish < n) {
            vis[idx] = true;
            for (int i = 0; i < n; ++i)
                if (!vis[i])
                    pq.push({-abs(pts[idx][0]-pts[i][0])-abs(pts[idx][1]-pts[i][1]) , i});
            while (vis[pq.top().second])
                pq.pop();
            res -= pq.top().first;
            idx = pq.top().second;
            pq.pop();
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    [[0,0],[2,2],[3,10],[5,2],[7,0]]
    vector<vector<int>> arr = {
        {0,0}, {2,2}, {3,10}, {5,2}, {7,0}
    };
    int res = sol.minCostConnectPoints(arr);
    cout << res << endl;
    return 0;
}
