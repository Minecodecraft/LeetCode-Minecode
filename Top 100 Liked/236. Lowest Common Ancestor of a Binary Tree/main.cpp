//
//  main.cpp
//  236. Lowest Common Ancestor of a Binary Tree
//
//  Created by 边俊林 on 2019/10/17.
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

// Solution 1: Now so good
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        findPath(root, p, path1);
        findPath(root, q, path2);
        path1.push_back(p);
        path2.push_back(q);
        unordered_set<TreeNode*> st2 (path2.begin(), path2.end());
        for (auto it = path1.rbegin(); it != path1.rend(); ++it)
            if (st2.count(*it) > 0) return *it;
        return NULL;
    }

private:
    bool findPath(TreeNode* pRoot, TreeNode* pTar, vector<TreeNode*>& st) {
        if (pRoot == NULL) return false;
        if (pRoot == pTar)
            return true;

        if (pRoot->left) {
            st.push_back(pRoot);
            if (findPath(pRoot->left, pTar, st))
                return true;
            st.pop_back();
        }
        if (pRoot->right) {
            st.push_back(pRoot);
            if (findPath(pRoot->right, pTar, st))
                return true;
            st.pop_back();
        }
        return false;
    }
};
 */

// Solution 2: More readable, more faster
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }

private:
    TreeNode* dfs(TreeNode* pRoot, TreeNode* p, TreeNode* q) {
        if (pRoot == p || pRoot == q || pRoot == NULL)
            return pRoot;
        TreeNode* p1 = dfs(pRoot->left, p, q);
        TreeNode* p2 = dfs(pRoot->right, p, q);
        if (p1 && p2)
            return pRoot;
        return p1 ? p1 : p2;
    }
};

int main() {

    Solution sol = Solution();

    TreeNode* n3 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(4);
    n3->left = n5; n3->right = n1;
    n5->left = n6; n5->right = n2;
    n2->left = n7; n2->right = n4;
    n1->left = n0; n0->right = n8;

    auto res = sol.lowestCommonAncestor(n3, n5, n1);
//    auto res = sol.lowestCommonAncestor(n3, n5, n4);
    cout << res->val << endl;

    return 0;
}
