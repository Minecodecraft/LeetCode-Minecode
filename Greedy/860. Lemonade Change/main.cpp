//
//  main.cpp
//  860. Lemonade Change
//
//  Created by 边俊林 on 2019/11/3.
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
    bool lemonadeChange(vector<int>& bills) {
        vector<int> tot (2, 0); // 5 10
        for(int bill: bills) {
            int exc = bill - 5;
            for (int i = 1; i >= 0; --i) {
                while (exc >= 5*(i+1) && tot[i]) {
                    exc -= 5*(i+1);
                    tot[i]--;
                }
                if (exc == 0) break;
            }
            if (exc) return false;
            if (bill == 5 || bill == 10)
                tot[bill/5-1]++;
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        5,5,5,5,10,5,10,10,10,20
    };
    bool res = sol.lemonadeChange(nums);
    cout << res << endl;
    return 0;
}
