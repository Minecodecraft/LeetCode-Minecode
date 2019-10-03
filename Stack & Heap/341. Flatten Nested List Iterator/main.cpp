//
//  main.cpp
//  341. Flatten Nested List Iterator
//
//  Created by 边俊林 on 2019/10/4.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/flatten-nested-list-iterator/
\* ------------------------------------------------------ */

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
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        arr = vector<int> ();
        readList(nestedList, arr);
    }

    int next() {
        return arr[idx++];
    }

    bool hasNext() {
        return idx < arr.size();
    }

private:
    vector<int> arr;
    int idx = 0;

    void readList(const vector<NestedInteger>& list, vector<int>& arr) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i].isInteger())
                arr.push_back(list[i].getInteger());
            else
                readList(list[i].getList(), arr);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {

    return 0;
}
