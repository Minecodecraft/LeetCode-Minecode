//
//  main.cpp
//  4. Median Of Two Sorted Arrays
//
//  Created by 边俊林 on 2018/6/6.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ------------------------------------------------------------------------- *\
    https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
\* ------------------------------------------------------------------------- */

#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
// Use Two-Pointers algorithm

/// Tips:
// Two-Pointers Problem: There's two ordered array that we should traverse both of them to get something like median
// Then we can use two pointer in both of them respective, and each loop we judge which one to go forward.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Judge if either of them is empry
        if (nums1.size() == 0) { return medianOfArray(nums2); }
        if (nums2.size() == 0) { return medianOfArray(nums1); }
        
        // Use Two-Pointers algorithm
        vector<int> num3;
        int totSize = (int)(nums1.size() + nums2.size());
        int mid = (int)totSize / 2.f;
        int isEven = !(totSize & 1);
        int p1, p2;
        double v1, v2;
        for (int i = p1 = p2 = 0; i < totSize; ++i) {
            // Judge to avoid out of range
            v1 = p1 < nums1.size() ? nums1[p1] : INT_MAX;
            v2 = p2 < nums2.size() ? nums2[p2] : INT_MAX;
            if (v1 < v2) {
                num3.push_back(v1);
                p1++;
            } else {
                num3.push_back(v2);
                p2++;
            }
            if (i == mid) {
                break;
            }
        }
        return (num3[mid]+num3[mid-isEven]) / 2.f;
    }
private:
    double medianOfArray(vector<int> &nums) {
        int mid = (int)nums.size() / 2;
        int isEven = !((int)nums.size() & 1);
        return (nums[mid]+nums[mid-isEven]) / 2.f;
    }
};

// Tool Function List
void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}

int main() {
    
    Solution sol = Solution();
    
    int arr1[] = {1, 2};
    int arr2[] = {3, 4};
    size_t size1 = sizeof(arr1) / sizeof(int);
    size_t size2 = sizeof(arr2) / sizeof(int);
    vector<int> v1 = vector<int>(arr1, arr1+size1);
    vector<int> v2 = vector<int>(arr2, arr2+size2);
    
    double res = sol.findMedianSortedArrays(v1, v2);
    
    printf("%lf\n", res);
    
    return 0;
}
