//
//  main.cpp
//  456. 132 Pattern
//
//  Created by 边俊林 on 2019/10/7.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/132-pattern/
\* ------------------------------------------------------ */

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
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> st;
        for (int i = nums.size()-1; i >= 0; --i) {
            if (nums[i] < s3) return true;
            else while (!st.empty() && nums[i] > st.top())
                s3 = st.top(), st.pop();
            st.push(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 2, 3, 4
//        3, 1, 4, 2
//        -1, 3, 2, 0
//        1, 0, 1, -4, -3
//        8,10,4,6,5
        3,5,0,3,4
    };
    bool res = sol.find132pattern(nums);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
