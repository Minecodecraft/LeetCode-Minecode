//
//  main.cpp
//  189. Rotate Array
//
//  Created by 边俊林 on 2019/10/23.
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
// Solution 1: Use two-pointer
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        return recursive(nums, k, 0, nums.size());
    }

private:
    void recursive(vector<int>& nums, int k, int beg, int len) {
        k %= len;
        if (k == 0) return;
        for (int i = 0; i < k; ++i) {
            swap(nums[beg+i], nums[nums.size()-(k-i)]);
        }
        recursive(nums, k, beg+k, len-k);
    }
};
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k  %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        1, 2, 3,4 ,5 ,6, 7
    };
    int k = 3;
    sol.rotate(nums, k);
    cout << nums.size() << endl;
    return 0;
}
