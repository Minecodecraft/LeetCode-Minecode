//
//  main.cpp
//  503. Next Greater Element II
//
//  Created by 边俊林 on 2019/10/8.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/next-greater-element-ii/
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
// Solution 1: Not so good, use too many temp variables, beat 10%
/*
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int, int>> st;
        map<int, int> pos;
        for (int i = 0; i < nums.size()*2; ++i) {
            int idx = i % nums.size();
            while (st.size() && st.top().first < nums[idx]) {
                pos[st.top().second] = nums[idx];
                st.pop();
            }
            if (i < nums.size()) st.emplace(nums[idx], idx);
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
            res.push_back(pos.count(i) > 0 ? pos[i] : -1);
        return res;
    }
};
 */

// Solution 2: Great and conciselly, beat 50%
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> nxt (nums.size(), -1);
        for (int i = 0; i < nums.size() * 2; ++i) {
            while (st.size() && nums[st.top()] < nums[i % nums.size()]) {
                nxt[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            if (i < nums.size()) st.push(i);
        }
        return nxt;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        1, 2, 1
//        100,1,11,1,120,111,123,1,-1,-100
    };
    vector<int> res = sol.nextGreaterElements(nums);
    cout << res.size() << endl;
    return 0;
}
