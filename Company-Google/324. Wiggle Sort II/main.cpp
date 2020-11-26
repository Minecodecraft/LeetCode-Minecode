//
//  main.cpp
//  324. Wiggle Sort II
//
//  Created by Jaylen Bian on 11/21/20.
//  Copyright © 2020 边俊林. All rights reserved.
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
        int n = (int)nums.size();
        if (n == 0) return;
#define num_after_swap(idx) nums[(1 + 2 * (idx)) % (n | 1)]

        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int median = nums[n/2];

        // 首先，通过nth_element处理后，左半边大于 median，右半边小于median，比如[6, 4, 5, 1, 1, 1]
        // 而此时，我们只需要将他们依次交叉放入即可，比如这种打乱idx的方式：[0,1,2,3,4,5] -> [1,3,5,0,2,4]
        // 那么，我们就可以写出转换方程 (1 + 2 * (idx)) % (n | 1)
        // 即: 奇数时为 (1 + 2i) % n, 偶数时为 (1 + 2i) % (n+1)
        // 然后，使用一个迭代器依次遍历，发现大的，就逐个填入属于大数的格子，idx = [1, 3, 5]
        // 发现小的，则逐个填入小的格子, idx = [4, 2, 0] (倒序填入，使循环退出条件能够为“填完所有格子”)
        int left = 0, right = n-1, it = 0;
        while (it <= right) {
            if (num_after_swap(it) > median) {
                swap(num_after_swap(left++), num_after_swap(it++));
            } else if (num_after_swap(it) < median) {
                swap(num_after_swap(right--), num_after_swap(it));
            } else {
                ++it;
            }
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 5, 1, 1, 6, 4};
    sol.wiggleSort(nums);
    for_each(nums.begin(), nums.end(), [](int& ele) { cout << ele << ","; });
    return 0;
}
