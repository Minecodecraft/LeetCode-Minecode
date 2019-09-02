//
//  main.cpp
//  321. Create Maximum Number
//
//  Created by 边俊林 on 2019/8/29.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
 \* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res (k, INT_MIN);
        for (int l = 0; l <= k; ++l) {
            int r = k - l;
            if (l > n1 || r > n2) continue;
            auto arr1 = getTopK(nums1, l);
            auto arr2 = getTopK(nums2, r);
            auto tmparr = mergeArr(arr1, arr2);
            if (isGreater(tmparr, 0, res, 0))
                res = tmparr;
        }
        return res;
    }

private:
    vector<int> getTopK(const vector<int>& arr, int k) {
        if (k <= 0) return {};
        vector<int> res (k, INT_MIN);
        int idx = 0;
        for (int i = 0; i < arr.size(); ++i) {
            while (idx > 0 && arr.size()-i+idx > k && arr[i] > res[idx-1]) --idx;
            if (idx < k)
                res[idx++] = arr[i];
        }
        return res;
    }

    vector<int> mergeArr(const vector<int>& nums1, const vector<int>& nums2) {
        int l = 0, r = 0, idx = 0, n1 = nums1.size(), n2 = nums2.size();
        vector<int> res (n1+n2, 0);
        while (idx < n1+n2) {
            res[idx++] = isGreater(nums1, l, nums2, r) ? nums1[l++] : nums2[r++];
        }
        return res;
    }

    bool isGreater(const vector<int>& larr, int l, const vector<int>& rarr, int r) {
        int nl = larr.size(), nr = rarr.size();
        while (l < nl && r < nr && larr[l] == rarr[r]) {
            ++l; ++r;
        }
        // 1. larr is at end
        if (l == nl)
            return false;
        // 2. rarr is at end
        if (r == nr)
            return true;
        // 3. larr rarr not equal at middle
        return larr[l] >= rarr[r];
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
//    vector<int> n1 = {3, 4, 6, 5};
//    vector<int> n2 = {9, 1, 2, 5, 8, 3};
//    int k = 5;
//    vector<int> n1 = {6,7};
//    vector<int> n2 = {6,0,4};
    //    int k = 5;
    vector<int> n1 = {2,5,6,4,4,0};
    vector<int> n2 = {7,3,8,0,6,5,7,6,2};
    int k = 15;
    auto res = sol.maxNumber(n1, n2, k);

    return 0;
}
