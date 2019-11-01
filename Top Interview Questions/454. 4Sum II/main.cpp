//
//  main.cpp
//  454. 4Sum II
//
//  Created by 边俊林 on 2019/11/1.
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
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        unordered_map<int, int> cnt;
        for (int& i: a)
            for (int& j: b)
                cnt[i+j]++;
        int res = 0;
        for (int& i: c)
            for (int& j: d)
                res += cnt[-i-j];
        return res;
    }
};

int main() {

    return 0;
}
