//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2020/3/8.
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
    string generateTheString(int n) {
        if (n == 1) {
            return "a";
        } else if (n & 1) {
            string res = "";
            for (int i = 0; i < n-2; ++i) {
                res += 'a';
            }
            res += 'b';
            res += 'c';
            return res;
        } else {
            string res = "";
            for (int i = 0; i < n-1; ++i) {
                res += 'a';
            }
            res += 'b';
            return res;
        }
        return "";
    }
};

int main() {
    Solution sol = Solution();
    for (int i = 1; i < 5; ++i) {
        cout << sol.generateTheString(i) << endl;
    }
    return 0;
}
