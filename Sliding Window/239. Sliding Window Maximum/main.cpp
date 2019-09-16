//
//  main.cpp
//  239. Sliding Window Maximum
//
//  Created by 边俊林 on 2019/9/16.
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
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
// Solution 1: Priority_queue (Heap), 64ms, not so good
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int len = nums.size();
        if (len < k || k == 0) return {};
        for (int i = 0; i < k-1; ++i)
            pq.push(make_pair(i, nums[i]));
        vector<int> res;
        for (int i = k-1; i < len; ++i) {
            pq.push(make_pair(i, nums[i]));
            while (i - pq.top().first >= k) {
                pq.pop();
            }
            res.push_back(pq.top().second);
        }
        return res;
    }

private:
    struct cmp {
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        }
    };
};
 */

// Solution 2: Use deque, 56ms
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        int len = nums.size();
        if (len < k || k == 0) return {};
        vector<int> res;
        for (int i = 0; i < len; ++i) {
            // clear prefix that not in window
            while (!dq.empty() && i - dq.front().first >= k)
                dq.pop_front();
            // insert & refresh suffix
            while (!dq.empty() && dq.back().second < nums[i])
                dq.pop_back();
            dq.push_back(make_pair(i, nums[i]));
            if (i >= k-1)
                res.push_back(dq.front().second);   // insert here
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1,3,-1,-3,5,3,6,7
    };
//    int k = 3;
    int k = 0;
    auto res = sol.maxSlidingWindow(nums, k);

    return 0;
}
