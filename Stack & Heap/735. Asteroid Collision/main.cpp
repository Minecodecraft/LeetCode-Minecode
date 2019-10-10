//
//  main.cpp
//  735. Asteroid Collision
//
//  Created by 边俊林 on 2019/10/10.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
 \* ------------------------------------------------------ */

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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for (int& item: asteroids) {
            while (item < 0 && st.size() && st.top() > 0) {
                int pre = st.top(); st.pop();
                if (pre == -item) {
                    item = 0;
                    break;
                } else if (pre > -item) {
                    item = pre;
                }
            }
            if (item != 0) st.push(item);
        }
        vector<int> res (st.size());
        for (int i = res.size()-1; i >= 0; --i)
            res[i] = st.top(), st.pop();
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        5, 10, -5
//        8, -8
//        10, 2, -5
    };
    auto res = sol.asteroidCollision(nums);
    auto f = [](int elem) { cout << elem << ", "; };
    for_each(res.begin(), res.end(), f);
    return 0;
}
