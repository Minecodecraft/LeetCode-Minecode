//
//  main.cpp
//  106. Construct Binary Tree from Inorder and Postorder Traversal
//
//  Created by Minecode on 2019/7/11.
//  Copyright © 2019 minecode. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeCore(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
private:
    TreeNode* buildTreeCore(vector<int>& inorder, int b1, int e1, vector<int>& postorder, int b2, int e2) {
        if (b2 > e2) return NULL;
        TreeNode* root = new TreeNode(postorder[e2]);
        int mid = e1;
        for (; ; mid--)
            if (inorder[mid] == postorder[e2]) break;
        root->left = buildTreeCore(inorder, b1, mid-1, postorder, b2, b2+mid-b1-1);
        root->right = buildTreeCore(inorder, mid+1, e1, postorder, b2+mid-b1, e2-1);
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
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    auto res = sol.buildTree(inorder, postorder);
    cout << res->val << endl;
    
    return 0;
}
