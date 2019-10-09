//
//  main.cpp
//  703. Kth Largest Element in a Stream
//
//  Created by 边俊林 on 2019/10/9.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/kth-largest-element-in-a-stream/
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
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->_capacity = k;
        for (int& num: nums) _add(num);
    }

    int add(int val) {
        _add(val);
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int _capacity;

    void _add(int val) {
        if (pq.size() == _capacity) {
            if (pq.top() >= val) return;
            else pq.pop();
        }
        pq.push(val);
    }
};

int main() {
    int k = 3;
    vector<int> nums = {
        4,5,8,2
    };
    KthLargest sol = KthLargest(k, nums);
    cout << sol.add(3) << endl;
    cout << sol.add(5) << endl;
    cout << sol.add(10) << endl;
    cout << sol.add(9) << endl;
    cout << sol.add(4) << endl;

    return 0;
}
