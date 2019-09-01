//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/9/1.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

// https://leetcode.com/contest/weekly-contest-152/problems/diet-plan-performance/

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
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int len = calories.size();
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < k; ++i)
            sum += calories[i];
        if (sum < lower)
            cnt--;
        else if (sum > upper)
            cnt++;
        for (int i = 1; i < len-k+1; ++i) {
            sum -= calories[i-1];
            sum += calories[i+k-1];
            if (sum < lower)
                cnt--;
            else if (sum > upper)
                cnt++;
        }
        return cnt;
    }
};

int main(int argc, const char * argv[]) {

    return 0;
}
