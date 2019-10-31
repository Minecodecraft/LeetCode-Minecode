//
//  main.cpp
//  371. Sum of Two Integers
//
//  Created by 边俊林 on 2019/10/31.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
    int getSum(int num, int carry) {
        if (carry == 0) return num;
        int sum = num ^ carry;
        // Use 0xffffffff to prevent runtime error
        // See here: https://leetcode.com/problems/sum-of-two-integers/discuss/302977/C%2B%2B%3A-the-evil-runtime-error%3A-left-shift-of-negative-value-reason-and-how-to-solve/283187/
        carry = (num & carry & 0xffffffff) << 1;
        return getSum(sum, carry);
    }
};

int main() {
    Solution sol = Solution();
//    int a = 1, b = 2;
    int a = -1, b = 1;
    int res = sol.getSum(a, b);
    cout << res << endl;
    return 0;
}
