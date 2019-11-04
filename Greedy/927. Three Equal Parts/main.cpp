//
//  main.cpp
//  927. Three Equal Parts
//
//  Created by 边俊林 on 2019/11/4.
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
    vector<int> threeEqualParts(vector<int>& A) {
        int cnt = 0, n = A.size();
        for (int num: A) if (num) ++cnt;
        if (cnt % 3) return {-1, -1};
        int leading = 0;
        for (int i = n-1; i >= 0; --i) {
            if (A[i] == 1) break;
            else ++leading;
        }
        if (cnt == 0)
            return {0, 2};
        int idx = 0;
        vector<int> res;
        stack<string> st;
        for (int i = 0; i < 3; ++i) {
            int onecnt = 0, zerocnt = 0;
            string str = "";
            while (idx < A.size() && onecnt < cnt/3) {
                if (A[idx] == 1) onecnt++;
                str += to_string(A[idx]);
                ++idx;
            }
            while (idx < A.size() && zerocnt < leading) {
                if (A[idx] == 1)
                    return {-1, -1};
                str += to_string(A[idx]);
                ++idx; ++zerocnt;
            }
            int tmp = 0;
            while (tmp < str.length() && str[tmp] == '0') ++tmp;
            str = str.substr(tmp);

            if (st.size() && st.top() != str)
                return {-1, -1};
            st.push(str);
            res.push_back(idx);
        }
        return {res[0]-1, res[1]};
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
        1,0,1,0,1
//        1,1,0,1,1
//        0,0,0,0,0
//        0,1,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0
    };
    auto res = sol.threeEqualParts(nums);
    cout << res[0] << "," << res[1] << endl;
    return 0;
}
