//
//  main.cpp
//  116. Populating Next Right Pointers in Each Node
//
//  Created by 边俊林 on 2019/10/20.
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
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root != NULL)
            q.push(root);
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                Node* pNode = q.front(); q.pop();
                if (sz) pNode->next = q.front();
                if (pNode->left) q.push(pNode->left);
                if (pNode->right) q.push(pNode->right);
            }
        }
        return root;
    }
};

int main() {

    return 0;
}
