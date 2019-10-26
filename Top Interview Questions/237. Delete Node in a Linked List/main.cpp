//
//  main.cpp
//  237. Delete Node in a Linked List
//
//  Created by 边俊林 on 2019/10/26.
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        auto nxtnode = node->next;
        *node = *nxtnode;
        delete nxtnode;
    }
};

int main() {
    Solution sol = Solution();

    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n1 = new ListNode(1);
    ListNode* n9 = new ListNode(9);
    n4->next = n5; n5->next = n1;
    n1->next = n9;

    sol.deleteNode(n5);

    return 0;
}
