//
//  main.cpp
//  43. Multiply Strings
//
//  Created by 边俊林 on 2019/7/22.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/multiply-strings/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> arr(MAXN, 0);
        int maxlen, overflow, p, level, num, tmp;
        maxlen = overflow = p = 0;
        for (int i = num1.length()-1; i >= 0; --i) {
            for (int j = num2.length()-1; j >= 0; --j) {
                level = (num1.length()-i-1) + (num2.length()-j-1);
                num = (num1[i]-'0') * (num2[j]-'0');
                while (overflow || num) {
                    tmp = (num % 10) + arr[level] + overflow;
                    overflow = tmp / 10;
                    num /= 10;
                    tmp %= 10;
                    arr[level++] = tmp;
                }
                maxlen = max(maxlen, level);
            }
        }
        return toStr(arr, maxlen);
    }
private:
    const int MAXN = 1e4+10;

    string toStr(vector<int>& arr, int len) {
        string res;
        for (int i = len-1; i >= 0; --i)
            res += (arr[i] + '0');
        return res;
    }
};



int main() {
    Solution sol = Solution();
//    string num1 = "2";
//    string num2 = "3";
//    string num1 = "123";
//    string num2 = "456";
//    string num1 = "0";
//    string num2 = "1";
    string num1 = "11111111111111111111111111";
    string num2 = "22222222222222222222222222";
    string res = sol.multiply(num1, num2);
    cout << res << endl;
    return 0;
}
