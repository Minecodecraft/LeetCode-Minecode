//
//  main.cpp
//  295. Find Median from Data Stream
//
//  Created by 边俊林 on 2019/10/3.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/find-median-from-data-stream/
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
class MedianFinder {
public:
    MedianFinder() { }

    void addNum(int num) {
        if (lq.size() > rq.size()) rq.push(num);
        else lq.push(num);

        if (!lq.empty() && !rq.empty() && lq.top() > rq.top()) {
            int lnum = lq.top(); lq.pop();
            int rnum = rq.top(); rq.pop();
            lq.push(rnum);
            rq.push(lnum);
        }
    }

    double findMedian() {
        if ((lq.size() + rq.size()) & 1)
            return lq.top();
        else
            return (double)(lq.top() + rq.top()) / 2;
    }

private:
    priority_queue<int> lq;
    priority_queue<int, vector<int>, greater<int>> rq;
};

int main() {
    MedianFinder sol = MedianFinder();
    sol.addNum(1);
    sol.addNum(2);
    cout << sol.findMedian() << endl;
    sol.addNum(3);
    cout << sol.findMedian() << endl;
    return 0;
}
