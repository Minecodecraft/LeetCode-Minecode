//
//  main.cpp
//  364. Nested List Weight Sum II
//
//  Created by 边俊林 on 2020/1/16.
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
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// Solution 1: 
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& list) {
        int weighted = 0, unweighted = 0;
        while (list.size()) {
            vector<NestedInteger> newlist = vector<NestedInteger>();
            for (auto& ele: list) {
                if (ele.isInteger())
                    unweighted += ele.getInteger();
                else {
                    auto tmp = ele.getList();
                    newlist.insert(newlist.begin(), tmp.begin(), tmp.end());
                }
            }
            weighted += unweighted;
            list = newlist;
        }
        return weighted;
    }
};

int main() {

    return 0;
}
