//
//  main.cpp
//  297. Serialize and Deserialize Binary Tree
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

// Solution 1: Recursive Solution, only beats 5%
class Codec {
public:
    string serialize(TreeNode* root) {
        string res = "";
        serializeCore(root, res);
        return res;
    }

    TreeNode* deserialize(string data) {
        return deserializeCore(data);
    }

private:
    void serializeCore(TreeNode* pRoot, string& res) {
        if (pRoot == NULL) {
            res += "#,";
            return;
        }
        res += to_string(pRoot->val) + ',';
        serializeCore(pRoot->left, res);
        serializeCore(pRoot->right, res);
    }

    TreeNode* deserializeCore(string& data) {
        if (data.empty()) return NULL;

        int idx = 0;
        while (data[idx] != ',') ++idx;
        string cur = data.substr(0, idx);
        data = data.substr(idx+1);
        if (cur == "#") {
            return NULL;
        }
        TreeNode* pNode = new TreeNode(stoi(cur));
        pNode->left = deserializeCore(data);
        pNode->right = deserializeCore(data);
        return pNode;
    }
};

int main() {
    Codec sol = Codec();

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    n1->left = n2; n1->right = n3;
    n3->left = n4; n3->right = n5;

    string res = sol.serialize(n1);
    cout << res << endl;

    TreeNode* resNode = sol.deserialize(res);
    cout << resNode->val << endl;
    return 0;
}
