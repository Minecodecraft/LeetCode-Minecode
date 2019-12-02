//
//  main.cpp
//  841. Keys and Rooms
//
//  Created by 边俊林 on 2019/12/2.
//  Copyright © 2019 边俊林. All rights reserved.
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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int sz = rooms.size();
        vector<bool> vis (sz, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while (q.size()) {
            int p = q.front(); q.pop();
            --sz;
            for (int v: rooms[p]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return sz == 0;
    }
};

int main() {

    return 0;
}
