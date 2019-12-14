//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2019/12/14.
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
    int findSpecialInteger(vector<int>& arr) {
        map<int, int> cnt;
        for (int& ele: arr) cnt[ele]++;
        return (*cnt.begin()).first;
    }
};

int main() {

    return 0;
}
