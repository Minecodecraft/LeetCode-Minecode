//
//  main.cpp
//  225. Implement Stack using Queues
//
//  Created by 边俊林 on 2019/10/3.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/implement-stack-using-queues/
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
class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size()-1; ++i)
            q.push(q.front()), q.pop();
    }

    int pop() {
        int tmp = q.front();
        q.pop();
        return tmp;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};

int main() {
    MyStack sol = MyStack();
    sol.push(1);
    sol.push(2);
    cout << sol.top() << endl;
    sol.push(3);
    cout << sol.top() << endl;
    cout << sol.empty() << endl;
    return 0;
}
