//
//  main.cpp
//  842. Split Array into Fibonacci Sequence
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
    vector<int> splitIntoFibonacci(string S) {
        vector<int> path;
        if (backtracking(S, 0, path))
            return path;
        return {};
    }
    
private:
    bool backtracking(string s, int idx, vector<int>& path) {
        if (idx == s.length())
            return true;
        
        for (int j = idx+1; j <= s.length(); ++j) {
            if (j > idx+1 && s[idx] == '0') break;
            long num = stol(s.substr(idx, j-idx));
            if (num > INT_MAX) break;
            if (path.size() < 2 ||
                (long)path.back() + (long)path[path.size()-2] == num) {
                path.push_back(num);
                if (backtracking(s, j, path) && path.size() > 2)
                    return true;
                path.pop_back();
            }
        }
        return false;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "123456579";
//    string s = "11235813";
//    string s = "112358130";
//    string s = "1101111";
//    string s = "5511816597";
    string s = "214748364721474836422147483641";
    vector<int> res = sol.splitIntoFibonacci(s);
    for_each(res.begin(), res.end(), [](int ele) { cout << ele << ","; });
    cout << endl;
    return 0;
}
