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

int main() {
    Solution sol = Solution();
    
    return 0;
}
