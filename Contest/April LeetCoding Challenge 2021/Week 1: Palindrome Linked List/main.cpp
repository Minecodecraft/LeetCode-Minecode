//
//  main.cpp
//  Week 1: Palindrome Linked List
//
//  Created by Jaylen Bian on 4/2/21.
//

/// Solution:
//
// Approach 1: iteration
/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        ListNode *pNode = head;
        while (pNode != NULL) {
            nums.push_back(pNode->val);
            pNode = pNode->next;
        }
        for (int i = 0, j = nums.size()-1; i <= j; i++, j--) {
            if (nums[i] != nums[j])
                return false;
        }
        return true;
    }
};
 */

// Approach 2: Recursion
/*
class Solution {
    bool recur(ListNode* pNode) {
        if (pNode == NULL)
            return true;
        if (!recur(pNode->next))
            return false;
        if (pHead->val != pNode->val)
            return false;
        pHead = pHead->next;
        return true;
    }
    ListNode* pHead;

public:
    bool isPalindrome(ListNode* head) {
        pHead = head;
        if (!recur(pHead))
            return false;
        return true;
    }
};
 */

// Approach 3: Reverse half of list, O(n) time and O(1) space
class Solution {
    ListNode *getFirstHalfEnd(ListNode *pNode) {
        ListNode *pSlow = pNode, *pFast = pNode;
        while (pFast->next && pFast->next->next) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        return pSlow;
    }

    ListNode *reverse(ListNode *pNode) {
        ListNode *pPrev = NULL, *pCurr = pNode, *pNext = NULL;
        while (pCurr) {
            pNext = pCurr->next;
            pCurr->next = pPrev;
            pPrev = pCurr;
            pCurr = pNext;
        }
        return pPrev;
    }

public:
    bool isPalindrome(ListNode* pHead) {
        if (pHead == NULL)
            return true;

        ListNode *firstHalfEnd = getFirstHalfEnd(pHead);
        ListNode *secondHalfStart = reverse(firstHalfEnd->next);

        ListNode *pLeft = pHead;
        ListNode *pRight = secondHalfStart;
        while (pLeft && pRight) {
            if (pLeft->val != pRight->val)
                return false;
            pLeft = pLeft->next;
            pRight = pRight->next;
        }
        return true;
    }
};

int main() {

    return 0;
}
