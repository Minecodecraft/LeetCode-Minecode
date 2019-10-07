//
//  main.cpp
//  496. Next Greater Element I
//
//  Created by 边俊林 on 2019/10/7.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/next-greater-element-i/
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int, int> nxt;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!st.empty() && st.top() < nums2[i]) {
                nxt[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i)
            res.push_back(nxt.count(nums1[i]) ? nxt[nums1[i]] : -1);
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> n1 = {4, 1, 2};
    vector<int> n2 = {1, 3, 4, 2};
//    vector<int> n1 = {2, 4};
//    vector<int> n2 = {1, 2, 3, 4};
    auto res = sol.nextGreaterElement(n1, n2);
    cout << res.size() << endl;
    return 0;
}
