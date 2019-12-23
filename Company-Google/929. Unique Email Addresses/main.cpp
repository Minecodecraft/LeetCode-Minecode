//
//  main.cpp
//  929. Unique Email Addresses
//
//  Created by 边俊林 on 2019/12/23.
//  Copyright © 2019 边俊林. All rights reserved.
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
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ress;
        for (auto& email: emails) {
            size_t pos = email.find('@');
            string res = "";
            for (int i = 0; i < pos; ++i) {
                if (email[i] == '+') break;
                else if (email[i] == '.') continue;
                res += email[i];
            }
            res += email.substr(pos);
            ress.insert(res);
        }
        return ress.size();
    }
};

int main() {
    Solution sol = Solution();
    vector<string> mat = {
        "test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"
    };
    int res = sol.numUniqueEmails(mat);
    cout << res << endl;
    return 0;
}
