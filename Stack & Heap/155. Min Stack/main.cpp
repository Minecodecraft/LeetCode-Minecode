//
//  main.cpp
//  155. Min Stack
//
//  Created by 边俊林 on 2019/9/27.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/min-stack/
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
class MinStack {
public:
    MinStack() { }

    void push(int x) {
        _st.push(x);
        if (_mst.empty() || _mst.top().second > x)
            _mst.push(make_pair(_st.size(), x));
    }

    void pop() {
        int sz = _st.size();
        _st.pop();
        while (!_mst.empty() && _mst.top().first >= sz)
            _mst.pop();
    }

    int top() {
        return _st.top();
    }

    int getMin() {
        if (_mst.empty()) return 0;
        return _mst.top().second;
    }

private:
    stack<int> _st;
    stack<pair<int, int>> _mst; // idx, num
};

int main() {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}
