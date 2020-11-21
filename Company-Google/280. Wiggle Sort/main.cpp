//
//  main.cpp
//  280. Wiggle Sort
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
        sort(nums.begin(), nums.end());
        int cnt = nums.size() / 2;
        for (int i = 1, j = nums.size() - cnt; i < j; i += 2, j++) {
            swap(nums[i], nums[j]);
        }
    }
};

int main() {

    return 0;
}
