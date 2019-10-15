//
//  main.cpp
//  136. Single Number
//
//  Created by 边俊林 on 2019/10/15.
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
    int singleNumber(vector<int>& nums) {
        unordered_set<int> st;
        for (auto& num: nums) {
            if (st.count(num) > 0) st.erase(num);
            else st.insert(num);
        }
        return *st.begin();
    }
};

int main() {

    return 0;
}
