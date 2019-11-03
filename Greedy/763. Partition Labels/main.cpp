//
//  main.cpp
//  763. Partition Labels
//
//  Created by 边俊林 on 2019/11/3.
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
    vector<int> partitionLabels(string S) {
        vector<vector<int>> range;
        for (int i = 0; i < 26; ++i) {
            int s = INT_MAX, e = INT_MIN;
            for (int j = 0; j < S.length(); ++j)
                if (S[j]-'a' == i)
                    s = min(s, j), e = max(e, j);
            if (s != INT_MAX)
                range.push_back({s, e});
        }
        
        sort(range.begin(), range.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || a[0]==b[0] && a[1] < b[1];
        });
        vector<int> res;
        int i, j, n = range.size();
        for (i = 0; i < n;) {
            int s = range[i][0], e = range[i][1];
            for (j = i; j < n; ++j) {
                if (range[j][0]>= s && range[j][0]<=e)
                    e = max(e, range[j][1]);
                else break;
            }
            res.push_back(e - s + 1);
            i = j;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    string s = "ababcbacadefegdehijhklij";
    auto res = sol.partitionLabels(s);
    for_each(res.begin(), res.end(), [](int ele) { cout << ele << ", "; });
    cout << endl;
    return 0;
}
