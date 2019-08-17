//
//  main.cpp
//  591. Tag Validator
//
//  Created by 边俊林 on 2019/8/17.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/tag-validator/
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
    bool isValid(string code) {
        int i = 0;
        return validTag(code, i) && i == code.length() ;
    }

private:
    bool validTag(string s, int& i) {
        int j = i;
        string tagstr = parseTagName(s, j);
        if (tagstr.empty()) return false;
        validContent(s, j);
        int tagend = j + tagstr.length() + 2;
        string tagendstr = "</" + tagstr + ">";
        if (tagend >= s.length() || s.substr(j, tagend-j+1) != tagendstr) return false;
        i = tagend + 1;
        return true;
    }

    string parseTagName(string s, int& i) {
        if (s[i] != '<') return "";
        int j = s.find('>', i);
        if (j == string::npos || j - i - 1 < 1 || j - i - 1 > 9) return "";
        string tagstr = s.substr(i+1, j-i-1);
        for (int idx = 0; idx < tagstr.length(); ++idx)
            if (!isupper(tagstr[idx])) return "";
        i = j+1;
        return tagstr;
    }

    void validContent(string s, int& i) {
        int j = i;
        while (j < s.length()) {
            if (!validContentText(s, j) && !validCData(s, j) && !validTag(s, j))
                break;
        }
        i = j;
    }

    bool validContentText(string s, int& i) {
        int tmp = i;
        while (i < s.length() && s[i] != '<') ++i;
        return i != tmp;
    }

    bool validCData(string s, int& i) {
        if (s.find("<![CDATA[", i) != i) return false;
        int j = s.find("]]>", i);
        if (j == string::npos) return false;
        i = j + 3;
        return true;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
//    string s = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";
//    string s = "<A>  <B> </A>   </B>";
    string s = "<A></A><B></B>";
    auto res = sol.isValid(s);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
