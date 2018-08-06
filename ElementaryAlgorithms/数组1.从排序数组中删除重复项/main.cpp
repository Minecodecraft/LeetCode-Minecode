//
//  main.cpp
//  Template
//
//  Created by 边俊林 on 2018/8/6.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/21/
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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int p = 0, maxx = nums[0]-1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > maxx) {
                maxx = nums[i];
                nums[p++] = maxx;
            }
        }
        return p;
    }
};

// Tool Function List


int main() {
    
    Solution sol = Solution();
    
    vector<int> v{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int res = sol.removeDuplicates(v);
    
    cout << res << endl;
    
    return 0;
}
