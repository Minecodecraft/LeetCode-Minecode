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
