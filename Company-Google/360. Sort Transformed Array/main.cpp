//
//  main.cpp
//  360. Sort Transformed Array
//
//  Created by Jaylen Bian on 1/7/21.
//  Copyright © 2021 边俊林. All rights reserved.
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
    int quad(int num, int a, int b, int c) {
        return a * num * num + b * num + c;
    }
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res (nums.size());
        int l = 0, r = nums.size()-1;
        int idx = a >= 0 ? nums.size()-1 : 0;
        while (l <= r) {
            if (a >= 0)
                res[idx--] = quad(nums[l], a, b, c) >= quad(nums[r], a, b, c) ? quad(nums[l++], a, b, c) : quad(nums[r--], a, b, c);
            else
                res[idx++] = quad(nums[l], a, b, c) <= quad(nums[r], a, b, c) ? quad(nums[l++], a, b, c) : quad(nums[r--], a, b, c);
        }
        return res;
    }
};

int main() {

    return 0;
}
