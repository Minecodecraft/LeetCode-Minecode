//
//  main.cpp
//  232. Implement Queue using Stacks
//
//  Created by 边俊林 on 2019/10/3.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/implement-queue-using-stacks/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class MyQueue {
public:
    MyQueue() { }

    void push(int x) {
        _insert(x);
    }

    int pop() {
        int tmp = st.top(); st.pop();
        return tmp;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }

private:
    stack<int> st;

    void _insert(int num) {
        if (!st.empty()) {
            int tmp = st.top(); st.pop();
            _insert(num);
            st.push(tmp);
        } else
            st.push(num);
    }
};

int main() {

    return 0;
}
