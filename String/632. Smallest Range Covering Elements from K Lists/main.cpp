//
//  main.cpp
//  632. Smallest Range Covering Elements from K Lists
//
//  Created by 边俊林 on 2019/8/17.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<vit, vit>, vector<pair<vit, vit>>, cmp> pq;
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for (auto &elem: nums) {
            pq.push({elem.begin(), elem.end()});
            minn = min(minn, elem[0]);
            maxx = max(maxx, elem[0]);
        }

        vector<int> res = {minn, maxx};
        while (true) {
            auto item = pq.top();
            pq.pop();
            ++item.first;
            if (item.first == item.second) break;
            pq.push(item);

            minn = *(pq.top().first);
            maxx = max(maxx, *(item.first));
            if (maxx-minn < res[1]-res[0])
                res = {minn, maxx};
        }
        return res;
    }

private:
    typedef vector<int>::iterator vit;
    struct cmp {
        bool operator() (pair<vit, vit> p1, pair<vit, vit> p2) {
            return *p1.first > *p2.first;
        }
    };
};

int main() {
    Solution sol = Solution();
//    vector<vector<int>> nums = {
//        {4, 10, 15, 24, 26},
//        {0, 9, 12, 20},
//        {5, 18, 22, 30}
//    };
//    vector<vector<int>> nums = {
//        {1, 2, 3},
//        {1, 2, 3},
//        {1, 2, 3}
//    };
    vector<vector<int>> nums = { {-2,87,89},{-24,40,72,77,87,91,92,92,92,92,93},{12,16,17,17,17,18},{9,19,20,21,22},{26,40,50,53,54,55},{8,35,37,37,37,38,38,40},{-15,37,37,39},{2,31,34,35,36,36,37,38,38,38,38,39},{10,28,65,72,76,79,79,80}
    };
    auto res = sol.smallestRange(nums);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
