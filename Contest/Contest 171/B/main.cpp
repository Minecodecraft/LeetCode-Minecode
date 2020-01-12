//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2020/1/12.
//  Copyright © 2020 边俊林. All rights reserved.
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
    int minFlips(int a, int b, int c) {
        long long mask = 1;
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (c & mask) { // c 1
                if (!(a & mask) &&  !(b & mask)) ++res;
            } else { // c 0
                if (a & mask) ++res;
                if (b & mask) ++res;
            }
            mask <<= 1;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    int a = 2, b = 6, c = 5;
    int a = 1, b = 2, c = 3;
    int res = sol.minFlips(a, b, c);
    cout << res << endl;
    return 0;
}
