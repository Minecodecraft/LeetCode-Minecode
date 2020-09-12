//
//  main.cpp
//  1110. Delete Nodes And Return Forest
//
//  Created by Jaylen Bian on 9/12/20.
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

/// Solution: 1
//
class Solution {
    unordered_set<int> st;
    bool solve(TreeNode* pRoot, vector<TreeNode *>& res, bool first) {
        if (pRoot == NULL)
            return true;

        if (st.count(pRoot->val)) {
            solve(pRoot->left, res, true);
            solve(pRoot->right, res, true);
            return false;
        }
        if (first)
            res.push_back(pRoot);
        if (pRoot->left && !solve(pRoot->left, res, false))
            pRoot->left = NULL;
        if (pRoot->right && !solve(pRoot->right, res, false))
            pRoot->right = NULL;
        return true;
    }



public:
    vector<TreeNode* > delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int dele: to_delete)
            st.insert(dele);

        vector<TreeNode *> res;
        solve(root, res, true);
        return res;
    }
};

// Solution 2: Just more clever way
class Solution {
    unordered_set<int> dele;
    TreeNode* helper(TreeNode* pRoot, vector<TreeNode *>& res, bool is_root) {
        if (pRoot == NULL) return NULL;
        bool deleted = dele.count(pRoot->val);
        if (is_root && !deleted) res.push_back(pRoot);
        pRoot->left = helper(pRoot->left, res, deleted);
        pRoot->right = helper(pRoot->right, res, deleted);
        return deleted ? NULL : pRoot;
    }



public:
    vector<TreeNode* > delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int item: to_delete)
            dele.insert(item);

        vector<TreeNode *> res;
        helper(root, res, true);
        return res;
    }
};

int main() {

    return 0;
}
