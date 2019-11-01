//
//  main.cpp
//  630. Course Schedule III
//
//  Created by 边俊林 on 2019/11/1.
//  Copyright © 2019 边俊林. All rights reserved.
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
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int curtime = 0;
        for (auto& course: courses) {
            curtime += course[0];
            pq.push(course[0]);
            if (curtime > course[1]) {
                curtime -= pq.top(); pq.pop();
            }
        }
        return pq.size();
    }
};

int main() {

    return 0;
}
