//
//  main.cpp
//  692. Top K Frequent Words
//
//  Created by 边俊林 on 2019/10/9.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/top-k-frequent-words/
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
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto word: words) mp[word]++;
        auto cmp = [] (pair<string, int>& a, pair<string, int>& b) {
            return  a.second == b.second ? a.first > b.first : a.second < b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for (auto& it: mp) pq.emplace(it.first, it.second);
        vector<string> res;
        while (k-- > 0)
            res.push_back(pq.top().first), pq.pop();
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> words = {
//        "i", "love", "leetcode", "i", "love", "coding"
        "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"
    };
//    int k = 2;
    int k = 4;
    auto res = sol.topKFrequent(words, k);
    cout << res.size() << endl;
    return 0;
}
