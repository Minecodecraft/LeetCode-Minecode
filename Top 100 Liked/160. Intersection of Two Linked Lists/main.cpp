//
//  main.cpp
//  160. Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt = 0;
        ListNode* pa = headA, * pb = headB;
        while (pa && pb) {
            pa = pa->next;
            pb = pb->next;
        }
        while (pa) pa = pa->next, --cnt;
        while (pb) pb = pb->next, ++cnt;

        pa = headA, pb = headB;
        while (cnt != 0) {
            if (cnt > 0) pb = pb->next, cnt--;
            else pa = pa->next, cnt++;
        }

        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;
        }
        return pa;
    }
};

int main() {
    Solution sol = Solution();
    return 0;
}
