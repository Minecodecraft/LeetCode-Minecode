//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2019/9/21.
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
class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int res = 0, sum = 0;
        for (res = 0; res < arr.size(); ++res) {
            if (sum + arr[res] > 5000) break;
            sum += arr[res];
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        100,200,150,1000
    };
    int res = sol.maxNumberOfApples(nums);
    cout << res << endl;
    return 0;
}
