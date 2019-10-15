//
//  main.cpp
//  19. Remove Nth Node From End of List
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
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return solve(head, n).first;
    }

private:
    pair<ListNode*, int> solve(ListNode* pRoot, int n) {
        if (pRoot->next == NULL)
            return {n==1 ? NULL: pRoot, 1};
        auto pir = solve(pRoot->next, n);
        if (pir.second == n-1)
            return {pir.first, pir.second+1};
        pRoot->next = pir.first;
        return {pRoot, pir.second+1};
    }
};

int main() {
    Solution sol = Solution();
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    auto res = sol.removeNthFromEnd(n1, 2);
    cout << res->val << endl;

    return 0;
}
