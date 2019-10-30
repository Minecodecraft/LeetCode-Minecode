//
//  main.cpp
//  324. Wiggle Sort II
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
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midit = nums.begin() + n/2;
        nth_element(nums.begin(), midit, nums.end());
        int mid = *midit;
        
        auto getidx = [n](int idx) { return (idx*2 + 1) % (n | 1); };
        int l = 0, r = nums.size()-1, idx = 0;
        while (idx <= r) {
            if (nums[getidx(idx)] > mid) {
                swap(nums[getidx(l)], nums[getidx(idx)]);
                ++l; ++idx;
            } else if (nums[getidx(idx)] < mid) {
                swap(nums[getidx(r)], nums[getidx(idx)]);
                --r;
            } else
                ++idx;
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 5, 1, 1, 6, 4
        5,3,1,2,6,7,8,5,5
    };
    sol.wiggleSort(nums);
    cout << nums.size() << endl;
    return 0;
}
