//
//  main.cpp
//  105. Construct Binary Tree from Preorder and Inorder Traversal
//
//  Created by Minecode on 2019/7/10.
//  Copyright © 2019 minecode. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeCore(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
private:
    TreeNode* buildTreeCore(vector<int>& preorder, int b1, int e1, vector<int>& inorder, int b2, int e2) {
        if (b1 > e1) return NULL;
        TreeNode* root = new TreeNode(preorder[b1]);
        int mid = b2;
        for (; ; mid++)
            if (inorder[mid] == preorder[b1]) break;
        root->left = buildTreeCore(preorder, b1+1, b1+mid-b2, inorder, b2, mid);
        root->right = buildTreeCore(preorder, b1+mid-b2+1, e1, inorder, mid+1, e2);
        return root;
    }
};

/// Tips:
//

// Tool Function List
void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}
void printVectors(vector<vector<int>> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printVector(*it);
    }
    printf("]\n");
}

int main() {
    
    Solution sol = Solution();
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    auto res = sol.buildTree(preorder, inorder);
    cout << res->val << endl;
    
    return 0;
}
