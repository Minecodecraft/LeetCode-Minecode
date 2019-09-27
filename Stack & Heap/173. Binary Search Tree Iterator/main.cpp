//
//  main.cpp
//  173. Binary Search Tree Iterator
//
//  Created by 边俊林 on 2019/9/27.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
 \* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode* pNode = root;
        while (pNode != NULL || !st.empty()) {
            while (pNode != NULL) {
                st.push(pNode);
                pNode = pNode->left;
            }
            pNode = st.top(); st.pop();
            tree.push_back(pNode->val);
            pNode = pNode->right;
        }
    }

    int next() {
        return tree[_idx++];
    }

    bool hasNext() {
        return _idx < tree.size();
    }

private:
    vector<int> tree;
    int _idx = 0;
};

int main() {
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n9 = new TreeNode(9);
    TreeNode* n15 = new TreeNode(15);
    TreeNode* n20 = new TreeNode(20);
    n7->left = n3;
    n7->right = n15;
    n15->left = n9;
    n15->right = n20;

    BSTIterator* obj = new BSTIterator(n7);
    cout << obj->next() << endl;
    cout << obj->next() << endl;
    cout << obj->next() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    return 0;
}
