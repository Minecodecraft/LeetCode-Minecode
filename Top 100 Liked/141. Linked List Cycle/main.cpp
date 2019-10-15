//
//  main.cpp
//  141. Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        while (second != NULL) {
            first = first->next;
            second = second->next;
            if (second == NULL) return false;
            second = second->next;
            if (first == second) return true;
        }
        return false;
    }
};

int main() {

    return 0;
}
