//
//  main.cpp
//  68. Text Justification
//
//  Created by 边俊林 on 2019/7/27.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/text-justification/
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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> len (words.size(), 0);
        vector<int> sum (words.size()+1, 0);
        for (int i = 0; i < words.size(); ++i) {
            len[i] = words[i].length();
            sum[i+1] = sum[i] + len[i];
        }
        int l, r, end;
        l = 0, r = words.size()-1;

        vector<string> res;
        while (l <= r) {
            end = calEnd(len, sum, maxWidth, l, r);
            res.push_back(rangedString(words, sum, l, end, maxWidth, end == r));
            l = end + 1;
        }
        return res;
    }

private:
    int calEnd(vector<int>& len, vector<int>& sum, int maxWidth, int l, int r) {
        int totlen, reallen, p = l + 1;
        while (p <= r) {
            totlen = sum[p+1] - sum[l];
            reallen = totlen + p-l;
            if (reallen > maxWidth) {
                --p;
                return p;
            }
            ++p;
        }
        return p-1;
    }

    string rangedString(vector<string>& word, vector<int>& sum, int l, int r, int maxWidth, bool isLast) {
        int totlen = sum[r+1] - sum[l], sptot = maxWidth-totlen, cnt = r-l+1;
        int splen = cnt > 1 ? sptot / (cnt-1) : 0;
        int plus1cnt = sptot - splen*(cnt-1);
        string s;
        for (int i = l; i <= r; ++i) {
            if (i > l) {
                if (isLast) s += ' ';
                else {
                    string tmp = string(splen, ' ');
                    if (i-l <= plus1cnt) tmp += ' ';
                    s += tmp;
                }
            }
            s += word[i];
        }
        while (s.length() < maxWidth)
            s += ' ';
        cout << s.length() << endl;
        return s;
    }
};

void printVector(vector<string> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c", it==v.begin() ? '\0' : ' ');
        cout << *it << endl;
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
//    vector<string> words = { "This", "is", "an", "example", "of", "text", "justification."};
//    int maxWidth = 16;
    vector<string> words = { "What","must","be","acknowledgment","shall","be"};
    int maxWidth = 16;
//    vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain",
//        "to","a","computer.","Art","is","everything","else","we","do"};
//    int maxWidth = 20;

    auto res = sol.fullJustify(words, maxWidth);
    printVector(res);
    return 0;
}
