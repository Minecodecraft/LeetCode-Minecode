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
// Solution 1: Ugly code, not concise, won't get Google offer. Too slow, beats 9%
// Solution 2: Optimize the logic of equal judgement, beats 90%
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
        int lastzerocnt = -1;
        for (int i = 0; i < 3; ++i) {
            int onecnt = 0, zerocnt = 0, allzerocnt = 0;
            while (idx < A.size() && onecnt < cnt/3) {
                if (A[idx] == 1) onecnt++;
                else if (onecnt) allzerocnt++;
                ++idx;
            }
            while (idx < A.size() && zerocnt < leading) {
                if (A[idx] == 1)
                    return {-1, -1};
                if (onecnt) allzerocnt++;
                ++idx; ++zerocnt;
            }

            if (lastzerocnt >= 0 && allzerocnt != lastzerocnt)
                return {-1, -1};
            lastzerocnt = allzerocnt;
            res.push_back(idx);
        }
        return {res[0]-1, res[1]};
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1,0,1,0,1
//        1,1,0,1,1
        0,0,0,0,0
//        0,1,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0
    };
    auto res = sol.threeEqualParts(nums);
    cout << res[0] << "," << res[1] << endl;
    return 0;
}
