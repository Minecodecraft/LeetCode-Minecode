//
//  main.cpp
//  206. Reverse Linked List
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* nxt_ptr = NULL, * prev = NULL;
        for (ListNode* remaining = head; remaining != NULL; ) {
            nxt_ptr = remaining->next;
            remaining->next = prev;
            prev = remaining;
            remaining = nxt_ptr;
        }
        return prev;
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2; n2->next = n3;
    n3->next = n4; n4->next = n5;

    Solution sol = Solution();
    auto res = sol.reverseList(n1);
    cout << res->val << endl;

    return 0;
}
