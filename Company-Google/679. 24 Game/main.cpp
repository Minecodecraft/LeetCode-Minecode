//
//  main.cpp
//  679. 24 Game
//
//  Created by Jaylen Bian on 8/14/20.
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
    const double EPS = 1e-6;

    vector<double> getValue(int l, int r, vector<int>& nums) {
        if (l == r)
            return {(double)nums[l]};

        vector<double> res;
        for (int i = l; i <= r-1; ++i) {
                vector<double> larr = getValue(l, i, nums);
                vector<double> rarr = getValue(i+1, r, nums);
                for (double lele: larr) {
                    for (double rele: rarr) {
                        res.push_back(lele+rele);
                        res.push_back(lele-rele);
                        res.push_back(lele*rele);
                        if (rele != 0)
                            res.push_back(lele/rele);
                }
            }
        }
        return res;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do {
            auto arr = getValue(0, nums.size()-1, nums);
            for (double ele: arr)
                if (abs(ele-24) <= EPS)
                    return true;
        } while (next_permutation(nums.begin(), nums.end()));

        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {3,4,6,7};
    bool res = sol.judgePoint24(arr);
    cout << res << endl;
    return 0;
}
