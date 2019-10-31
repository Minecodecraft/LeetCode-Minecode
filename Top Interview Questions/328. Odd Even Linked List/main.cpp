//
//  main.cpp
//  328. Odd Even Linked List
//
//  Created by 边俊林 on 2019/10/30.
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* pOdd = NULL, * pEven = NULL;
        ListNode** pOddit = &pOdd, ** pEvenit = &pEven;
        ListNode* pNode = head;
        
        while (pNode != NULL) {
            (*pOddit) = pNode;
            pOddit = &((*pOddit)->next);
            pNode = pNode->next;
            
            if (pNode) {
                (*pEvenit) = pNode;
                pEvenit = &((*pEvenit)->next);
                pNode = pNode->next;
            }
        }
        
        *pOddit = pEven;
        *pEvenit = NULL;
        return pOdd;
    }
};

int main() {
    Solution sol = Solution();
    
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2; n2->next = n3;
    n3->next = n4; n4->next = n5;
    
    auto root = sol.oddEvenList(n1);
    cout << root->val << endl;
    
    return 0;
}
