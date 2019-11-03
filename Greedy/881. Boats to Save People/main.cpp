//
//  main.cpp
//  881. Boats to Save People
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
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int> st (people.begin(), people.end());
        int res = 0;
        while (st.size()) {
            int cur = *st.begin();
            st.erase(st.begin());
            auto it = st.upper_bound(limit-cur);
            if (it != st.begin()) {
                st.erase(prev(it));
            }
            res++;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 2
//        3, 2, 2, 1
        3, 5, 3, 4
    };
//    int limit = 3;
    int limit = 5;
    int res = sol.numRescueBoats(nums, limit);
    cout << res << endl;
    return 0;
}
