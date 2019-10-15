//
//  main.cpp
//  101. Symmetric Tree
//
//  Created by 边俊林 on 2019/10/15.
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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode* > vec;
        vec.push_back(root);
        int beg = 0;
        while (vec.size() > beg) {
            int sz = vec.size() - beg;
            if (beg > 0 && (sz & 1)) return false;
            for (int i = 0; i < sz/2; ++i) {
                if (vec[beg+i] == NULL && vec[beg + sz-i-1] == NULL) continue;
                if (vec[beg+i] == NULL || vec[beg + sz-i-1] == NULL) return false;
                if (vec[beg+i]->val != vec[beg + sz-i-1]->val) return false;
            }
            for (int i = 0; i < sz; ++i) {
                if (vec[beg+i] == NULL) continue;
                vec.push_back(vec[beg+i]->left);
                vec.push_back(vec[beg+i]->right);
            }
            beg += sz;
        }
        return true;
    }
};


int main() {
    Solution sol = Solution();
//    TreeNode* n1 = new TreeNode(1);
//    TreeNode* n21 = new TreeNode(2);
//    TreeNode* n22 = new TreeNode(2);
//    TreeNode* n31 = new TreeNode(3);
//    TreeNode* n32 = new TreeNode(4);
//    TreeNode* n33 = new TreeNode(4);
//    TreeNode* n34 = new TreeNode(3);
//    n1->left = n21; n1->right = n22;
//    n21->left = n31; n21->right = n32;
//    n22->left = n33; n22->right = n34;

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n21 = new TreeNode(2);
    TreeNode* n22 = new TreeNode(2);
    TreeNode* n31 = new TreeNode(3);
    TreeNode* n32 = new TreeNode(3);
    n1->left = n21; n1->right = n22;
    n21->right = n31;
    n22->right = n32;

    bool res = sol.isSymmetric(n1);
    cout << res << endl;
    return 0;
}
