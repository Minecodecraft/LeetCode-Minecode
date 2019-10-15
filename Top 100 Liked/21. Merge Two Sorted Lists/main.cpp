//
//  main.cpp
//  21. Merge Two Sorted Lists
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pRoot = new ListNode(-1), *pNode = pRoot;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val)
                pNode->next = l1, l1 = l1->next;
            else
                pNode->next = l2, l2 = l2->next;
            pNode = pNode->next;
        }
        while (l1 != NULL) {
            pNode->next = l1;
            pNode = pNode->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            pNode->next = l2;
            pNode = pNode->next;
            l2 = l2->next;
        }
        return pRoot->next;
    }
};

int main() {
    Solution sol = Solution();
    
    return 0;
}
