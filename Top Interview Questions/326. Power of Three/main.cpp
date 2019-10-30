//
//  main.cpp
//  326. Power of Three
//
//  Created by 边俊林 on 2019/10/30.
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
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

int main() {
    Solution sol = Solution();
//    int n = 27;
    int n = 0;
//    int n = 45;
    cout << sol.isPowerOfThree(n) << endl;
    return 0;
}
