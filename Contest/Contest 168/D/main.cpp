//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2019/12/22.
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
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        sz = status.size();
        vis = vector<bool> (sz, false);

        for (int idx: initialBoxes)
            openbox(idx, status, candies, keys, containedBoxes);
        return tot;
    }

private:
    int sz, tot = 0;
    vector<bool> vis;
    unordered_set<int> qboxs;
    unordered_set<int> qkeys;

    void openbox(int idx, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes) {
        if (vis[idx]) return;
        if (status[idx] == 0) {
            if (qkeys.count(idx))
                qkeys.erase(idx);
            else {
                qboxs.insert(idx);
                return;
            }
        }
        vis[idx] = true;
        tot += candies[idx];

        for (int& key: keys[idx])  {
            if (vis[key]) continue;
            qkeys.insert(key);
        }
        for (int& box: containedBoxes[idx]) {
            openbox(box, status, candies, keys, containedBoxes);
        }
        for (const int& box: qboxs) {
            openbox(box, status, candies, keys, containedBoxes);
        }
    }
};

int main() {

    return 0;
}
