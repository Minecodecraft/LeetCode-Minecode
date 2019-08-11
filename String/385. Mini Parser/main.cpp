//
//  main.cpp
//  385. Mini Parser
//
//  Created by 边俊林 on 2019/8/11.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/mini-parser/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
//class NestedInteger {
//    public:
//    // Constructor initializes an empty nested list.
//    NestedInteger();
//
//    // Constructor initializes a single integer.
//    NestedInteger(int value);
//
//    // Return true if this NestedInteger holds a single integer, rather than a nested list.
//    bool isInteger() const;
//
//    // Return the single integer that this NestedInteger holds, if it holds a single integer
//    // The result is undefined if this NestedInteger holds a nested list
//    int getInteger() const;
//
//    // Set this NestedInteger to hold a single integer.
//    void setInteger(int value);
//
//    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
//    void add(const NestedInteger &ni);
//
//    // Return the nested list that this NestedInteger holds, if it holds a nested list
//    // The result is undefined if this NestedInteger holds a single integer
//    const vector<NestedInteger> &getList() const;
//};

class NestedInteger {
public:
    NestedInteger() { }

    NestedInteger(int value) {
        this->val = value;
    }

    bool isInteger() const {
        return true;
    }

    int getInteger() const {
        return val;
    }

    void setInteger(int value) {
        val = value;
    }

    void add(const NestedInteger &ni) {
        vec.push_back(ni);
    }

    const vector<NestedInteger> &getList() const {
        return vec;
    }

private:
    int val = 0;
    vector<NestedInteger> vec;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        int idx = 0;
        return deserializeCore(s, idx);
    }

private:
    NestedInteger deserializeCore(string& s, int& idx) {
        if (s[idx] == '[')
            return deserializeList(s, idx);
        return deserializeNumber(s, idx);
    }

    NestedInteger deserializeNumber(string& s, int& idx) {
        int p = idx;
        while (p < s.length() && (isdigit(s[p]) || s[p] == '-')) ++p;
        if (p > idx) {
            string tmp = s.substr(idx, p-idx);
            idx = p;
            return NestedInteger(stoi(tmp));
        }
        idx = p;
        return NestedInteger(0);
    }

    NestedInteger deserializeList(string& s, int& idx) {
        NestedInteger ni;
        while (s[idx] != ']') {
            ++idx;
            if (s[idx] == ']') break;
            ni.add(deserializeCore(s, idx));
        }
        ++idx;
        return ni;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "[324]";
//    string s = "324";
    string s = "[123,[456,[789]]]";
//    string s = "[]";
    auto res = sol.deserialize(s);
    cout << res.getInteger() << endl;
    return 0;
}
