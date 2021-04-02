//
//  main.cpp
//  973. K Closest Points to Origin
//
//  Created by Jaylen Bian on 4/2/21.
//  Copyright © 2021 边俊林. All rights reserved.
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
    struct Node {
        int x, y, val;

        Node(int x, int y, int val) : x(x), y(y), val(val) {}
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        vector<Node> nodes;
        for (int i = 0; i < pts.size(); i++) {
            int x = pts[i][0], y = pts[i][1];
            Node node = Node(x, y, x*x + y*y);
            nodes.push_back(node);
        }

        sort(nodes.begin(), nodes.end(), [](Node &lhs, Node &rhs) {
            return lhs.val <= rhs.val;
        });
        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back({nodes[i].x, nodes[i].y});
        }
        return res;
    }
};

int main() {

    return 0;
}
