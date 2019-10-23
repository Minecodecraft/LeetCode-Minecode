//
//  main.cpp
//  179. Largest Number
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
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto& num: nums)
            strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), [](string& a, string& b) {
            return a+b > b+a;
        });
        string res = "";
        for (auto& str: strs)
            res += str;
        int idx = 0;
        while (idx < res.length() && res[idx] == '0') {
            ++idx;
        }
        if (idx == res.length()) --idx;
        res.erase(res.begin(), res.begin()+idx);
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        10, 2
//        3,30,34,5,9
//        121, 12
        12, 121
//        12, 122
//        0, 0
//        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };
    string res = sol.largestNumber(nums);
    cout << res << endl;
    return 0;
}
