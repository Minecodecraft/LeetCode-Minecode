//
//  main.cpp
//  217. Contains Duplicate
//
//  Created by 边俊林 on 2019/10/26.
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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> vis;
        for (auto& num: nums) {
            if (vis.count(num)) return true;
            vis.insert(num);
        }
        return false;
    }
};

int main() {

    return 0;
}
