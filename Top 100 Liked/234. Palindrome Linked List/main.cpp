//
//  main.cpp
//  234. Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        int cnt = 0;
        ListNode* pNode = head;
        while (pNode)
            pNode = pNode->next, ++cnt;
        stack<int> st;
        pNode = head;
        for (int i = 0; i < (cnt/2); ++i) {
            st.push(pNode->val);
            pNode = pNode->next;
        }
        if (cnt & 1) pNode = pNode->next;
        while (pNode) {
            if (pNode->val != st.top()) return false;
            st.pop();
            pNode = pNode->next;
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
//    n1->next = n2;

    bool res = sol.isPalindrome(n1);
    cout << (res ? "true" : "false") << endl;

    return 0;
}
