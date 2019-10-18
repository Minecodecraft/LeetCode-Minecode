//
//  main.cpp
//  406. Queue Reconstruction by Height
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res (people.size());
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];
        };
        sort(people.begin(), people.end(), cmp);

        for (auto& pir: people) {
            int idx = 0, cnt = 0;
            while (cnt < pir[1]) {
                if (!res[idx].size() || res[idx][0] >= pir[0]) ++cnt;
                ++idx;
            }
            while (res[idx].size()) ++idx;
            res[idx] = pir;
        }

        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> people = {
        {7, 0}, {4, 4}, {7,1}, {5, 0}, {6, 1}, {5, 2}
//        {2,4},{3,4},{9,0},{0,6},{7,1},{6,0},{7,3},{2,5},{1,1},{8,0}
    };
    auto res = sol.reconstructQueue(people);
    cout << res.size() << endl;
    return 0;
}
