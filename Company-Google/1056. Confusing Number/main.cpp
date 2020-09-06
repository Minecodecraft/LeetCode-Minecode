//
//  main.cpp
//  1056. Confusing Number
//
//  Created by Jaylen Bian on 9/6/20.
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
    unordered_map<int, int> rev = {
        {0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}
    };
    unordered_set<int> st = {
        0, 1, 6, 8, 9
    };

public:
    bool confusingNumber(int N) {
        int n = N, res = 0;
        while (n) {
            int tmp = n % 10;
            n /= 10;
            if (!st.count(tmp))
                return false;
            res = res * 10 + rev[tmp];
        }
        return res != N;
    }
};

int main() {

    return 0;
}
