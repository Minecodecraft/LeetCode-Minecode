//
//  main.cpp
//  987. Vertical Order Traversal of a Binary Tree
//
//  Created by Jaylen Bian on 11/26/20.
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution 1: Use DFS
/**
class Solution {
    map<int, map<int, vector<int>>> vals;

    void dfs(TreeNode *root, int x, int y) {
        vals[x][y].push_back(root->val);
        if (root->left)
            dfs(root->left, x-1, y+1);
        if (root->right)
            dfs(root->right, x+1, y+1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for (auto it = vals.begin(); it != vals.end(); ++it) {
            auto& submp = it->second;
            vector<int> tmp;
            for (auto subit = submp.begin(); subit != submp.end(); ++subit) {
                vector<int>& vec = subit->second;
                if (vec.size() >= 2)
                    sort(vec.begin(), vec.end());
                for (int ele: vec)
                    tmp.push_back(ele);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
 */

// Solution 2: Use BFS, no improvement, just for practice.
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> tot;
        queue<pair<int, TreeNode *>> q;
        q.emplace(0, root);
        while (!q.empty()) {
            int len = q.size();
            map<int, set<int>> submp;
            for (int i = 0; i < len; ++i) {
                auto& pir = q.front();
                submp[pir.first].insert(pir.second->val);
                if (pir.second->left)
                    q.emplace(pir.first-1, pir.second->left);
                if (pir.second->right)
                    q.emplace(pir.first+1, pir.second->right);
                q.pop();
            }
            for (auto kv: submp)
                for (int ele: kv.second)
                    tot[kv.first].push_back(ele);
        }
        vector<vector<int>> res;
        for (auto kv: tot)
            res.push_back(kv.second);
        return res;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}
