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
// Solution 1: Use array, O(nlogn) for sort, but O(n) for every time delete element. Not so good
/*
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
 */

// Solution 2: Use multiset to optimize the time complexity of deleting element
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> st (A.begin(), A.end());
        for (int i = 0; i < B.size(); ++i) {
            auto it = *st.rbegin() <= B[i] ? st.begin() : st.upper_bound(B[i]);
            A[i] = *it;
            st.erase(it);
        }
        return A;
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
