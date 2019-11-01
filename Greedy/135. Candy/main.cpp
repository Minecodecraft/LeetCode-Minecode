//
//  main.cpp
//  135. Candy
//
//  Created by 边俊林 on 2019/11/1.
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
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> res (n, 1);
        for (int i = 1; i < n; ++i)
            if (ratings[i] > ratings[i-1])
                res[i] = res[i-1]+1;
        for (int i = n-2; i >= 0; --i)
            if (ratings[i] > ratings[i+1])
                res[i] = max(res[i], res[i+1]+1);
        return accumulate(res.begin(), res.end(), 0);
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 0, 2
//        1, 2, 2
        1,3,4,5,2
    };
    int res = sol.candy(nums);
    cout << res << endl;
    return 0;
}
