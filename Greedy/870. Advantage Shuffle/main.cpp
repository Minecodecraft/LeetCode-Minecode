//
//  main.cpp
//  870. Advantage Shuffle
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
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector<int> res;
        for (int ele: B) {
            auto it = upper_bound(A.begin(), A.end(), ele);
            if (it == A.end()) {
                it = A.begin();
            }
            res.push_back(*it);
            A.erase(it);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> a = {2,7,11,15};
    vector<int> b = {1,10,4,11};
    vector<int> res = sol.advantageCount(a, b);
    for_each(res.begin(), res.end(), [](int ele) { cout << ele << ","; });
    cout << endl;
    return 0;
}
