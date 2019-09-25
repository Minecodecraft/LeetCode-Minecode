//
//  main.cpp
//  1052. Grumpy Bookstore Owner
//
//  Created by 边俊林 on 2019/9/25.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/grumpy-bookstore-owner/
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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int len = customers.size();
        vector<int> ones;
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            if (grumpy[i] == 1) ones.push_back(i);
            else sum += customers[i];
        }
        int l = 0, r = 0, res = sum, tot = 0;
        for (r = 0; r < ones.size(); ++r) {
            while (ones[r] - ones[l] + 1 > X) {
                tot -= customers[ones[l++]];
            }
            tot += customers[ones[r]];
            res = max(res, sum + tot);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> cus = {
//        1,0,1,2,1,1,7,5
        9,10,4,5
    };
    vector<int> gru = {
//        1,0,1,2,1,1,7,5
        1,0,1,1
    };
//    int X = 3;
    int X = 1;
    int res = sol.maxSatisfied(cus, gru, X);
    cout << res << endl;
    return 0;
}
