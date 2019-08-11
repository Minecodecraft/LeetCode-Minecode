//
//  main.cpp
//  345. Reverse Vowels of a String
//
//  Created by 边俊林 on 2019/8/11.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/reverse-vowels-of-a-string/
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
    string reverseVowels(string s) {
        if (s.length() <= 0)
            return s;
        int l = 0, r = s.length()-1;
        while (l < r) {
            while (l < s.length() && vowels.find(s[l]) == vowels.end()) ++l;
            while (r >= 0 && vowels.find(s[r]) == vowels.end()) --r;
            if (l < r)
                swap(s[l++], s[r--]);
        }
        return s;
    }

private:
    unordered_set<char> vowels = {
        'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'
    };
};

int main() {
    Solution sol = Solution();
    string s = "hello";
    auto res = sol.reverseVowels(s);
    cout << res << endl;
    return 0;
}
