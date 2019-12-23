//
//  main.cpp
//  4. Median of Two Sorted Arrays
//
//  Created by 边俊林 on 2019/12/23.
//  Copyright © 2019 边俊林. All rights reserved.
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
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int n = nums1.size(), m = nums2.size();

        int left = kth(nums1, nums2, (n+m+1) / 2);
        if ((n + m) & 1) return left;
        int right = kth(nums1, nums2, (n+m+1) / 2 + 1);
        return ((double)0.0 + left + right) / 2.0;
    }

private:
    int kth(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        if (n == 0) return m == 0 ? 0 : nums2[k-1];

        int l = 0, r = min(n, k-1);
        while (l < r) {
            int i = l + (r-l)/2, j = k-i-1;
            if (i > 0 && nums1[i-1] > nums2[j]) {
                r = i;
            } else if (j > 0 && nums2[j-1] > nums1[i]) {
                l = i+1;
            } else {
                l = i;
                break;
            }
        }
        int res = 0;
        if (l >= n) res = nums2[k-l-1];
        else if (k-l-1 >= m) res = nums1[l];
        else res = min(nums1[l], nums2[k-l-1]);
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> n1 = {
//        1, 3
        1, 2
//        1,3,5,6,7,8,9,11
//        1, 2
    };
    vector<int> n2 = {
//        2
        3, 4
//        1,4,6,8,12,14,15,17
//        1
//        -1, 3
    };
    double res = sol.findMedianSortedArrays(n1, n2);
    cout << res << endl;

    return 0;
}
