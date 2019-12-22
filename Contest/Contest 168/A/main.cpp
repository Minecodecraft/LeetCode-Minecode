//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2019/12/22.
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
    int findNumbers(vector<int>& nums) {
        int div = 10;
        vector<int> lines = {0};
        for (int i = 0; i < 6; ++i) {
            lines.push_back(div-1);
            div *= 10;
        }
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = lower_bound(lines.begin(), lines.end(), nums[i]) - lines.begin();
            if ((idx & 1) == 0) ++cnt;
        }
        return cnt;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> mat = {
        12,345,2,6,7896
    };
    int res = sol.findNumbers(mat);
    cout << res << endl;
    return 0;
}
