//
//  main.cpp
//  133. Clone Graph
//
//  Created by 边俊林 on 2019/11/13.
//  Copyright © 2019 边俊林. All rights reserved.
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
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        return copyNode(*node);
    }

private:
    unordered_map<int, Node*> _nodes;

    Node* copyNode(Node& ori) {
        if (_nodes.count(ori.val) > 0)
            return _nodes[ori.val];

        Node* newNode = new Node();
        newNode->val = ori.val;
        _nodes[ori.val] = newNode;
        for (auto& nei: ori.neighbors)
            newNode->neighbors.push_back(copyNode(*nei));
        return newNode;
    }
};

int main() {

    return 0;
}
