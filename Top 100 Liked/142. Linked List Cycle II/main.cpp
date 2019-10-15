//
//  main.cpp
//  142. Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        int cnt = 0;
        while (second != NULL) {
            first = first->next;
            second = second->next;
            if (second == NULL)
                return NULL;
            second = second->next;
            ++cnt;
            if (first == second) break;
        }
        if (second == NULL)
            return NULL;

        first = second = head;
        while (cnt--) second = second->next;
        while (first != second) {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};

int main() {
//    ListNode* n1 = new ListNode(3);
//    ListNode* n2 = new ListNode(2);
//    ListNode* n3 = new ListNode(0);
//    ListNode* n4 = new ListNode(4);
//    n1->next = n2; n2->next = n3;
//    n3->next = n4; n4->next = n2;

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    n1->next = n2;

    Solution sol = Solution();
    auto res = sol.detectCycle(n1);
    cout << (res == NULL) << endl;
    return 0;
}
