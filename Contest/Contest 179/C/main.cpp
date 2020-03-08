//
//  main.cpp
//  C
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
        vector<Node *> workers = {};
        int time = 0;

        Node() {
            this->workers = {};
            this->time = 0;
        }
    };
    int res = 0;
    void dfs(Node *pNode, int tot) {
        res = max(res, tot);
        if (pNode == NULL)
            return;
        tot += pNode->time;
        for (auto& worker: pNode->workers) {
            dfs(worker, tot);
        }
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<Node *> all (n);
        for (int i = 0; i < n; ++i) all[i] = new Node();

        for (int i = 0; i < n; ++i) {
            all[i]->time = informTime[i];
            if (manager[i] != -1) {
                all[manager[i]]->workers.push_back(all[i]);
            }
        }
        dfs(all[headID], 0);
        return res;
    }

};

int main() {
    Solution sol = Solution();
    int n = 7, head = 6;
    vector<int> mana = {1,2,3,4,5,6,-1};
    vector<int> inf = {0,6,5,4,3,2,1};
    int res = sol.numOfMinutes(n, head, mana, inf);
    cout << res << endl;
    return 0;
}
