//
//  main.cpp
//  56. Merge Intervals
//
//  Created by 边俊林 on 2018/7/20.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ---------------------------------------------------------- *\
 https://leetcode-cn.com/problems/merge-intervals/description/
\* ---------------------------------------------------------- */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
// The key is to order the sequence.
// So use cmp function to sort the vector, and traverse to calculate the range.

/// Tips:
//

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res = {intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back().end < intervals[i].start) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = max(intervals[i].end, res.back().end);
            }
        }
        return res;
    }
private:
    static inline bool cmp(Interval a, Interval b) {
        return a.start < b.start;
    }
};

void printVector(vector<Interval> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c(%d, %d)", it==v.begin() ? '\0' : ' ', (*it).start, (*it).end);
    }
    printf("]\n");
}

int main() {
    
    Solution sol = Solution();
    
    vector<Interval> v {Interval(1, 4), Interval(4,5)};
    auto res = sol.merge(v);
    
    printVector(res);
    
    return 0;
}
