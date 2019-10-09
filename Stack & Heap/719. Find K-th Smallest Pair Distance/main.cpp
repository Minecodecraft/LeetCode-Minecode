//
//  main.cpp
//  719. Find K-th Smallest Pair Distance
//
//  Created by 边俊林 on 2019/10/9.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
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
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 2) return 0;
        int l = 0, r = nums[n-1] - nums[0];
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (count(nums, mid) < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

private:
    int count(vector<int>& arr, int tar) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int fir = arr[i], sec = tar+fir;   // sec < tar + fir
            auto begIt = arr.begin()+i+1;
            auto curcnt = upper_bound(begIt, arr.end(), sec) - begIt;
            cnt += curcnt;
        }
        return cnt;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 3, 1
//        1, 3, 1, 4, 5, 6
//        62,100,4
        9,10,7,10,6,1,5,4,9,8
//        1, 1, 1, 1, 1
    };
//    int k  = 1;
//    int k  = 3;
//    int k  = 2;
    int k = 18;
    int res = sol.smallestDistancePair(nums, k);
    cout << res << endl;
    return 0;
}
