//
//  main.cpp
//  215. Kth Largest Element in an Array
//
//  Created by 边俊林 on 2019/9/27.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/kth-largest-element-in-an-array/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
// Solution 1: Use heap to sort all the elemants, and remove the last n-k, not so good
/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int &elem: nums) pq.push(elem);
        for (int i = 1; i < k; ++i)
            pq.pop();
        return pq.top();
    }
};
 */

// Solution 2: Use STL, it's better to read the source code
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin()+k, nums.end(), greater<>());
        return nums[k-1];
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        3,2,1,5,6,4
        3,2,3,1,2,4,5,5,6
    };
//    int k = 2;
    int k = 4;
    int res = sol.findKthLargest(nums, k);
    cout << res << endl;
    return 0;
}
