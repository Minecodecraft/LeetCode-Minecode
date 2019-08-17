//
//  main.cpp
//  609. Find Duplicate File in System
//
//  Created by 边俊林 on 2019/8/17.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/find-duplicate-file-in-system/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        hash.clear();
        for (auto path: paths)
            parsePath(path);
        vector<vector<string>> res;
        for (auto item: hash) {
            if (item.second.size() > 1)
                res.push_back(item.second);
        }
        return res;
    }

private:
    unordered_map<string, vector<string>> hash;
    void parsePath(const string& s) {
        stringstream ss (s);
        string prefix;
        ss >> prefix;
        string tmp;
        while (ss >> tmp) {
            int beg = tmp.find("(");
            string filename = tmp.substr(0, beg);
            string content = tmp.substr(beg+1, tmp.length()-beg-2);
            hash[content].push_back(prefix + "/" + filename);
        }
    }
};

// Tool Function List
void printVector(vector<string> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c", it==v.begin() ? '\0' : ' ');
        cout << *it << endl;
    }
    printf("]\n");
}
void printVectors(vector<vector<string>> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printVector(*it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
    vector<string> paths = {
//        "root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"
        "root/a 1.txt(abcd) 2.txt(efsfgh)","root/c 3.txt(abdfcd)","root/c/d 4.txt(efggdfh)"
    };
    auto res = sol.findDuplicate(paths);
    printVectors(res);
    return 0;
}
