//
//  main.cpp
//  303. Range Sum Query - Immutable
//
//  Created by 边俊林 on 2019/8/28.
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
class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum = vector<int> (nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            sum[i] = sum[i-1] + nums[i-1];
        }
    }

    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }

private:
    vector<int> sum;
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray sol = NumArray(nums);
    int res;
    res = sol.sumRange(0, 2);
    cout << res << endl;
    res = sol.sumRange(2, 5);
    cout << res << endl;
    res = sol.sumRange(0, 5);
    cout << res << endl;
    return 0;
}
