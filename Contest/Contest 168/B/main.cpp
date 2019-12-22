//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/12/22.
//  Copyright © 2019 边俊林. All rights reserved.
//

#include <iostream>

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
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int& num: nums) mp[num]++;

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second == 0) continue;
            int tot = it->second, cur = it->first;
            for (int i = 0; i < k; ++i) {
                if (mp.count(cur) == 0 || mp[cur] < tot) return false;
                mp[cur++] -= tot;
            }
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {
        1,2,3,3,4,4,5,6
    };
    int k = 4;
    bool res = sol.isPossibleDivide(arr, k);
    cout<< res << endl;
    return 0;
}
