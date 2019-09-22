//
//  main.cpp
//  992. Subarrays with K Different Integers
//
//  Created by 边俊林 on 2019/9/20.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
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
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return countOfAtMost(A, K) - countOfAtMost(A, K-1);
    }

private:
    int countOfAtMost(const vector<int>& A, int K) {
        int l = 0, r = 0, res = 0;
        unordered_map<int, int> cnt;
        for (r = 0; r < A.size(); ++r) {
            if (cnt[A[r] - 'a']++ == 0)
                K--;
            while (K < 0) {
                if (++cnt[A[l++] - 'a'] > 0)
                    ++K;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
