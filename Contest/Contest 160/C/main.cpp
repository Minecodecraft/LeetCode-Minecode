//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/10/27.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
/*
class Solution {
public:
    int maxLength(vector<string>& arr) {
//        int sz = arr.size();
//        vector<vector<int>> cnt (sz, vector<int> (26, 0));
//        for (int i = 0; i < sz; ++i) {
//            string& str = arr[i];
//            for (auto& ch: str) cnt[i][ch-'a']++;
//        }
//        int res = 0;
//        for (int i = 0; i < sz; ++i)
//            recursiveSearch(cnt, arr, i, {}, res)
//        return res;

        int sz = arr.size();
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            recursiveSearch(arr, arr[i], i, res);
        }
        return res;
    }

private:
//    void recursiveSearch(vector<vector<int>>& cnt, vector<string>& arr, int idx, vector<int>& curcnt, int& res) {
//
//    }

    void recursiveSearch(vector<string>& arr, string str, int idx, int& res) {
        sort(str.begin(), str.end());
        auto it = unique(str.begin(), str.end());
        if (it != str.end()) return;
        if (str.length() > res)
            res = str.length();

        for (int i = idx+1; i < arr.size(); ++i) {
            if (str.length() + arr[i].length() > 26) continue;
            recursiveSearch(arr, str + arr[i], i+1, res);
        }
    }
};
 */

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int sz = arr.size();
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            recursiveSearch(arr, arr[i], i+1, res);
        }
        return res;
    }

private:
    void recursiveSearch(vector<string>& arr, string str, int idx, int& res) {
        sort(str.begin(), str.end());
        auto it = unique(str.begin(), str.end());
        if (it != str.end())
            return;
        if (str.length() > res)
            res = str.length();

        for (int i = idx; i < arr.size(); ++i) {
            if (str.length() + arr[i].length() > 26) continue;
            recursiveSearch(arr, str + arr[i], i+1, res);
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<string> arr = {
//        "un","iq","ue"
//        "cha","r","act","ers"
//        "abcdefghijklmnopqrstuvwxyzzz"
        "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p"
    };
    int res = sol.maxLength(arr);
    cout << res << endl;
    return 0;
}
