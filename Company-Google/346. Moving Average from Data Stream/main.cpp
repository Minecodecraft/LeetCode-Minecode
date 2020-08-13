//
//  main.cpp
//  346. Moving Average from Data Stream
//
//  Created by Jaylen Bian on 8/13/20.
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
class MovingAverage {
    int _sz;
    queue<int> q;
    long long sum = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        _sz = size;
    }

    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > _sz) {
            sum -= q.front();
            q.pop();
        }
        return (double)sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main() {

    return 0;
}
