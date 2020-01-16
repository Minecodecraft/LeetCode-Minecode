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

// Solution 1: Non recursive, non `depth`
/*
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
 */

// Solution 2: DFS
// Hints: x + 2y + 3z = (3+1) * (x+y+z) - (3x+2y+z), so we can calculate the `delta`, `sum` (sum of all number) and `totdepth` (total depth)
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int overflow = dfs(nestedList, 1);
        return sum * (totdepth + 1) - overflow;
    }

private:
    int sum = 0;
    int totdepth = 1;

    int dfs(vector<NestedInteger>& list, int depth) {
        int cursum = 0;
        totdepth = max(totdepth, depth);
        for (auto& ele: list) {
            if (ele.isInteger()) {
                sum += ele.getInteger();
                cursum += depth * ele.getInteger();
            } else {
                auto tmp = ele.getList();
                cursum += dfs(tmp, depth+1);
            }
        }
        return cursum;
    }
};

int main() {

    return 0;
}
