//
//  main.cpp
//  1053. Previous Permutation With One Swap
//
//  Created by 边俊林 on 2019/11/8.
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
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        int l = n-2;
        while (l >= 0) {
            if (A[l] > A[l+1]) break;
            --l;
        }
        if (l < 0) return A;

        int r = n-1;
        while (r > l) {
            if (A[r] < A[l]) {
                while (A[r] == A[r-1]) --r;
                break;
            }
            --r;
        }
        swap(A[l], A[r]);
        return A;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        3,2,1
//        1,1,5
//        1,9,4,6,7
        3,1,1,3
    };
    auto res = sol.prevPermOpt1(nums);
    for_each(begin(res), end(res), [](int ele) { cout << ele << ", "; });
    cout << endl;
    return 0;
}
