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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> dif(arr.size()-1);
        for (int i = 0; i < arr.size()-1; ++i) {
            dif[i] = arr[i+1] - arr[i];
        }
        int mindif = *min_element(dif.begin(), dif.end());
        vector<vector<int>> res;
        for (int i = 0; i < arr.size()-1; ++i) {
            if (arr[i+1] - arr[i] == mindif) {
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        4, 2, 1 ,3
        3,8,-10,23,19,-4,-14,27
    };
    auto res = sol.minimumAbsDifference(nums);

    return 0;
}
