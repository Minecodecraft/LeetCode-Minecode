//
//  main.cpp
//  273. Integer to English Words
//
//  Created by 边俊林 on 2019/8/8.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/integer-to-english-words/
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
    string numberToWords(int num) {
        string str = to_string(num);
        auto len = str.length();
        // edge cases
        if (num == 0) return mapping[num];

        vector<string> arr;
        if (len > 9) { // Billion
            int beg = max(0, (int)len-9-3);
            int end = min(3, (int)len-9);
            if (addAfterResolve(arr, str.substr(beg, end)))
                arr.push_back("Billion");
        }
        if (len > 6) { // Million
            int beg = max(0, (int)len-6-3);
            int end = min(3, (int)len-6);
            if (addAfterResolve(arr, str.substr(beg, end)))
                arr.push_back("Million");
        }
        if (len > 3) { // Thousands
            int beg = max(0, (int)len-3-3);
            int end = min(3, (int)len-3);
            if (addAfterResolve(arr, str.substr(beg, end)))
                arr.push_back("Thousand");
        }
        int beg = max(0, (int)len-0-3);
        int end = min(3, (int)len);
        addAfterResolve(arr, str.substr(beg, end));

        string res = "";
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0) res += " ";
            res += arr[i];
        }
        return res;
    }

private:
    bool addAfterResolve(vector<string>& arr, string str) {
        auto res = resolve(str);
        if (!res.empty()) {
            arr.push_back(res);
            return true;
        }
        return false;
    }

    string resolve(string str) {
        int val = stoi(str);
        int tmp;
        vector<string> arr;
        if (val >= 100) {
            tmp = val / 100;
            arr.push_back(mapping[tmp]);
            arr.push_back("Hundred");
        }
        val %= 100;
        tmp = -1;

        for (int i = 0; i < numberOf1x.size(); ++i) {
            if (val != numberOf1x[i]) continue;
            tmp = numberOf1x[i];
            break;
        }
        if (tmp != -1) {
            arr.push_back(mapping[tmp]);
        } else {
            for (int i = 0; i < numberOfx0.size(); ++i) {
                if (val < numberOfx0[i]) continue;
                tmp = numberOfx0[i];
                break;
            }
            if (tmp != -1) {
                val -= tmp;
                arr.push_back(mapping[tmp]);
            }
            if (val > 0)
                arr.push_back(mapping[val]);
        }

        string res = "";
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0) res += " ";
            res += arr[i];
        }
        return res;
    }

    vector<int> numberOf1x = {19, 18, 17, 16, 15, 14, 13, 12, 11};
    vector<int> numberOfx0 = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    unordered_map<int, string> mapping = {
        {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"},
        {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {10, "Ten"}, {0, "Zero"},
        {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"},
        {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"},
        {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"},
    };
};

int main() {
    Solution sol = Solution();
//    int num = 123;
//    int num = 1234567;
//    int num = 1234567891;
//     int num = 1001;
//    int num = 100;
//    int num = 1000;
    int num = 1000000;
    string res = sol.numberToWords(num);
    cout << res << endl;
    return 0;
}
