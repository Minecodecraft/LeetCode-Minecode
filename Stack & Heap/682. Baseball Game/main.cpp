//
//  main.cpp
//  682. Baseball Game
//
//  Created by 边俊林 on 2019/10/9.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
 \* ------------------------------------------------------ */

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
    int calPoints(vector<string>& ops) {
        stack<int> score;

        for (string& op: ops) {
            if (op == "C")
            score.pop();
            else if (op == "D")
            score.push(score.top() * 2);
            else if (op == "+") {
                int a = score.top(); score.pop();
                int b = score.top(); score.pop();
                score.push(b); score.push(a); score.push(a+b);
            } else
            score.push(stoi(op));
        }

        int res = 0;
        while (score.size())
        res += score.top(), score.pop();
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> ops = {
//        "5","2","C","D","+"
        "5","-2","4","C","D","9","+","+"
    };
    int res = sol.calPoints(ops);
    cout << res << endl;
    return 0;
}
