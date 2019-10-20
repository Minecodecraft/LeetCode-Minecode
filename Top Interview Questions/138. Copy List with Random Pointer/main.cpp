//
//  main.cpp
//  138. Copy List with Random Pointer
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
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* pRoot = NULL, **pNode = &pRoot, * pCurr = head;
        unordered_map<int, Node*> mp;
        while (pCurr) {
            *pNode = new Node(pCurr->val, NULL, NULL);
            mp[pCurr->val] = *pNode;
            pCurr = pCurr->next;
            pNode = &(*pNode)->next;
        }
        pNode = &pRoot, pCurr = head;
        while (pCurr) {
            (*pNode)->random = pCurr->random ? mp[pCurr->random->val] : NULL;
            pCurr = pCurr->next;
            pNode = &(*pNode)->next;
        }
        return pRoot;
    }
};

int main() {
    Solution sol = Solution();

    Node* n1 = new Node(1, NULL, NULL);
    Node* n2 = new Node(2, NULL, NULL);

    n1->next = n2;
    n1->random = n2;
    n2->random = n2;

    auto res = sol.copyRandomList(n1);
    cout << res->val << endl;

    return 0;
}
