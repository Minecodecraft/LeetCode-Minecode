//
//  main.cpp
//  230. Kth Smallest Element in a BST
//
//  Created by 边俊林 on 2019/10/26.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

#include <iostream>

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res = search(root, k);
        return res[k-1];
    }

private:
    vector<int> search(TreeNode* root, int k) {
        if (root == NULL)
            return {};
        vector<int> vec = search(root->left, k);
        if (vec.size() >= k) return vec;
        vec.push_back(root->val);
        if (vec.size() >= k) return vec;
        vector<int> tmpr = search(root->right, k);
        vec.insert(vec.end(), tmpr.begin(), tmpr.end());
        return vec;
    }
};

int main() {
    Solution sol = Solution();

//    TreeNode* n3 = new TreeNode(3);
//    TreeNode* n1 = new TreeNode(1);
//    TreeNode* n4 = new TreeNode(4);
//    TreeNode* n2 = new TreeNode(2);
//    n3->left = n1;
//    n1->right = n2;
//    n3->right = n4;

    TreeNode* n5 = new TreeNode(5);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n6 = new TreeNode(6);
    n5->left = n3; n5->right = n6;
    n3->left = n2; n3->right = n4;
    n2->left = n1;

    int res = sol.kthSmallest(n3, 3);
    cout << res << endl;

    return 0;
}
