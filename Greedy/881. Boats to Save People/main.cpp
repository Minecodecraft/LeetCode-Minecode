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
// Solution 1: O(nlogn), but code is not concisely
/*
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
 */

// Solution 2
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int i = 0, j, res = 0;
        for (j = people.size()-1; i <= j; ++res, --j) {
            if (people[i] + people[j] <= limit) ++i;
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
