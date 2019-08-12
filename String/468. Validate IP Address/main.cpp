//
//  main.cpp
//  468. Validate IP Address
//
//  Created by 边俊林 on 2019/8/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/validate-ip-address/
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
    string validIPAddress(string IP) {
        int type = 0;
        for (int i = 0; i < IP.length(); ++i) {
            if (IP[i] == '.' || IP[i] == ':') {
                type = IP[i] == '.' ? 1 : 2;
            }
        }
        if (type == 1 && isIPv4(IP))
            return "IPv4";
        else if (type == 2 && isIPv6(IP))
            return "IPv6";
        return "Neither";
    }

private:
    bool isIPv4(string IP) {
        int cnt = 0, idx = 0;
        while (idx < IP.length()) {
            int r = idx;
            while (r < IP.length() && isdigit(IP[r])) ++r;
            if (r - idx > 4) return false;
            if (r - idx > 1 && IP[idx] == '0') return false;

            if (r > idx) {
                string tmp = IP.substr(idx, r-idx);
                int num = stoi(tmp);
                if (num < 0 || num > 255)
                    return false;
            } else
                return false;
            ++cnt;

            if (cnt >= 4 && r < IP.length())
                return false;
            if (r == IP.length() || IP[r] == '.')
                r++;
            if (r < IP.length() && !isdigit(IP[r]))
                return false;
            idx = r;
        }
        return cnt == 4;
    }

    bool isIPv6(string IP) {
        int cnt = 0, idx = 0;
        while (idx < IP.length()) {
            int r = idx;
            while (r < IP.length() && isV6AvaiableCh(IP[r])) ++r;
            if (r - idx > 4)
                return false;
            ++cnt;

            if (cnt >= 8 && r < IP.length())
                return false;
            if (r == IP.length() || IP[r] == ':')
                r++;
            if (r < IP.length() && !isV6AvaiableCh(IP[r]))
                return false;
            idx = r;
        }
        return cnt == 8;
    }

    bool isV6AvaiableCh(char& ch) {
        if (isdigit(ch))
            return true;
        if ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))
            return true;
        return false;
    }
};

int main() {
    Solution sol = Solution();
//    string IP = "172.16.254.1";
//    string IP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
//    string IP = "256.256.256.256";
//    string IP = "1111111";
//    string IP = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
    string IP = "01.01.01.01";
    auto res = sol.validIPAddress(IP);
    cout << res << endl;
    return 0;
}
