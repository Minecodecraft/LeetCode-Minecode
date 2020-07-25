//
//  main.cpp
//  937. Reorder Data in Log Files
//
//  Created by Jaylen Bian on 7/25/20.
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
struct Node {
    string signal;
    string content;
    bool isDigit;
    int digitIdx = -1;
};

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<Node> nodes;
        int digitIdx = 0;
        for (string& log: logs) {
            Node node = Node();
            int i = 0;
            while (i < log.length() && log[i] != ' ') ++i;
            node.signal = log.substr(0, i++);
            node.content = log.substr(i, log.length() - i);
            node.isDigit = log[i] >= '0' && log[i] <= '9';
            node.digitIdx = node.isDigit ? digitIdx++ : -1;
            nodes.push_back(node);
        }

        auto cmp = [](Node& a, Node& b) {
            if (a.isDigit && b.isDigit)
                return a.digitIdx < b.digitIdx;
            if (a.isDigit || b.isDigit)
                return b.isDigit;
            if (a.content != b.content)
                return a.content < b.content;
            return a.signal < b.signal;
        };

        sort(nodes.begin(), nodes.end(), cmp);
        vector<string> res;
        for (Node& node: nodes) {
            string str = node.signal + " ";
            str += node.content;
            res.push_back(str);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> logs = {
        "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"
    };
    auto res = sol.reorderLogFiles(logs);
    for_each(res.begin(), res.end(), [](string& str) { cout << str << endl; });
    return 0;
}
