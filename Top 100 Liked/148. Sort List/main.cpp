//
//  main.cpp
//  148. Sort List
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

// Solution 1: QuickSort, O(nlogn) time complexity, O(nlogn) space complexity
/*
class Solution {
public:
    ListNode* sortList(ListNode* head, ListNode* tail = NULL) {
        if (head != tail) {
            ListNode* smaller = NULL;
            ListNode** smaller_nxt = &smaller;
            for (ListNode** ptr = &(head->next); *ptr != tail; ) {
                if (head->val > (**ptr).val) {
                    *smaller_nxt = *ptr;
                    smaller_nxt = &((**smaller_nxt).next);
                    *ptr = (**ptr).next;
                } else {
                    ptr = &((**ptr).next);
                }
            }
            *smaller_nxt = head;

            head->next = sortList(head->next, tail);
            head = sortList(smaller, head);
        }
        return head;
    }
};
 */

// Solution 2: Merge Sort, O(nlogn) time complexity, O(1) space complexity
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        bool done = !head;
        for (int step = 1; !done; step *= 2) {
            done = true;
            ListNode** nxt_ptr = &head;
            ListNode* nxt_head = head;
            vector<ListNode*> sublists (2, NULL);
            do {
                for (ListNode*& sublist: sublists) {
                    sublist = nxt_head;
                    ListNode* tail = NULL;
                    for (int i = 0; i < step && nxt_head; ++i, nxt_head = nxt_head->next) {
                        tail = nxt_head;
                    }
                    if (tail) tail->next = NULL;
                }
                done &= !nxt_head;

                if (!sublists[1]) {
                    *nxt_ptr = sublists[0];
                } else {
                    while (sublists[0]|| sublists[1]) {
                        int idx = 0;
                        if (!sublists[1]) idx = 0;
                        else if (!sublists[0]) idx = 1;
                        else if (sublists[0]->val > sublists[1]->val) idx = 1;
                        *nxt_ptr = sublists[idx];
                        sublists[idx] = sublists[idx]->next;
                        nxt_ptr = &((**nxt_ptr).next);
                    }
                    *nxt_ptr = NULL;
                }
            } while (nxt_head);
        }
        return head;
    }
};

int main() {
    Solution sol = Solution();

    ListNode* n4 = new ListNode(4);
    ListNode* n2 = new ListNode(2);
    ListNode* n1 = new ListNode(1);
    ListNode* n3 = new ListNode(3);
    n4->next = n2; n2->next = n1;
    n1->next = n3;

    auto res = sol.sortList(n4);
    cout << res->val << endl;

    return 0;
}
