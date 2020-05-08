//
//  main.cpp
//  271. Encode and Decode Strings
//
//  Created by Jaylen Bian on 4/15/20.
//  Copyright © 2020 边俊林. All rights reserved.
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
// Solution 1: My solution with bad time complexity
/*
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        char ch = (int)0;
        string res = "";

        for (auto& str: strs) {
            for (auto& c: str) {
                res += '/';
                res += to_string(c-ch);
            }
            res += '#';
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int p = 0;
        string str = "";
        while (p != s.length()) {
            while (s[p] == '/') {
                int n = 0; ++p;
                while (p < s.length() && isdigit(s[p])) {
                    n = n * 10 + s[p++] - '0';
                }
                str += (char)(n);
            }
            if (s[p++] == '#') {
                res.push_back(str);
                str = "";
            }
        }
        return res;
    }
};
 */

// Solution 2: Faster solution
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto& str: strs) {
            res += to_string(str.length()) + "#" + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int p = 0;
        while (p < s.length()) {
            int it = s.find_first_of('#', p);
            int len = stoi(s.substr(p, it - p));
            p = it + 1;
            res.push_back(s.substr(p, len));
            p += len;
        }
        return res;
    }
};

int main() {

    Codec sol = Codec();
    vector<string> strs = {
        "hello world!", "haas123", "@#@$!&*(!@#", "sd21!#!"
    };
    string s = sol.encode(strs);
    auto res = sol.decode(s);
    for_each(res.begin(), res.end(), [](auto& str) { cout << str << endl; });

    return 0;
}
