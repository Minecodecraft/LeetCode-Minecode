//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/12/15.
//  Copyright © 2019 边俊林. All rights reserved.
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
    vector<int> sequentialDigits(int low, int high) {
        vector<long> nums;
        for (int i = 1; i <= 9; ++i)
            makeNums(i, nums);
        auto begit = lower_bound(nums.begin(), nums.end(), low);
        auto endit = upper_bound(nums.begin(), nums.end(), high);
        return vector<int> (begit, endit);
    }

private:
    void makeNums(int len, vector<long>& nums) {
        string str = "";
        for (int i = 1; i <= len; ++i)
            str.push_back('0'+i);
        nums.push_back(stol(str));
        for (int beg = len+1; beg <= 9; ++beg) {
            str = str.substr(1);
            str.push_back('0'+beg);
            nums.push_back(stol(str));
        }
    }
};

int main() {
    Solution sol = Solution();
//    int low = 100, high = 300;
    int low = 1000, high = 1000;
    auto res = sol.sequentialDigits(low, high);
    for_each(res.begin(), res.end(), [](int ele) {cout << ele << ", ";  });
    cout << endl;
    return 0;
}
