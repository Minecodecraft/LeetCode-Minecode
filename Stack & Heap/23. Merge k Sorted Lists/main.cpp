//
//  main.cpp
//  23. Merge k Sorted Lists
//
//  Created by 边俊林 on 2019/9/26.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/merge-k-sorted-lists/
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode *>, cmp> pq;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i] != NULL) pq.push(lists[i]);
        ListNode* pRoot, *pCurr;
        pRoot = pCurr = new ListNode(-1);
        while (!pq.empty()) {
            ListNode* pNode = pq.top();
            pq.pop();
            if (pNode->next != NULL)
                pq.push(pNode->next);
            pCurr = pCurr->next = pNode;
        }
        return pRoot->next;
    }

private:
    struct cmp {
        bool operator () (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};

int main() {
    Solution sol = Solution();
    ListNode* n11 = new ListNode(1);
    ListNode* n12 = new ListNode(4);
    ListNode* n13 = new ListNode(5);
    n11->next = n12; n12->next = n13;
    ListNode* n21 = new ListNode(1);
    ListNode* n22 = new ListNode(3);
    ListNode* n23 = new ListNode(4);
    n21->next = n22; n22->next = n23;
    ListNode* n31 = new ListNode(2);
    ListNode* n32 = new ListNode(6);
    n31->next = n32;
    vector<ListNode *> lists = {
        n11, n21, n31
    };
    auto res = sol.mergeKLists(lists);
    while (res != NULL) {
        cout << res->val << "->";
        res = res->next;
    }
    return 0;
}
