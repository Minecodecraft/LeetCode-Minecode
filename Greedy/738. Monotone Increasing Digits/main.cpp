//
//  main.cpp
//  738. Monotone Increasing Digits
//
//  Created by 边俊林 on 2019/11/2.
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
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int len = str.length();
        
        int upidx = len;
        for (int i = len-1; i > 0; --i) {
            if (str[i] < str[i-1]) {
                upidx = i;
                str[i-1] = str[i-1]-1;
            }
        }
        for (int i = upidx; i < len; ++i) str[i] = '9';
        return stoi(str);
    }
};

int main() {
    Solution sol = Solution();
    int n = 1234;
    int res = sol.monotoneIncreasingDigits(n);
    cout << res << endl;
    return 0;
}
