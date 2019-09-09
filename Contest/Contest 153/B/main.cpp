//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/9/8.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <stack>
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
    string dayOfTheWeek(int day, int month, int year) {
        // 1972 1 1 星期五
        bool isRun = (year-1968) % 4 == 0;
        int runcnt = (year-1-1968) / 4;
        int yeardif = year - 1971;

        // days in previous year
        int daycnt = (yeardif - runcnt) * 365 + runcnt * 366;
        daycnt += getdaycnt(month, day, isRun);
        daycnt--;
        return dateOf(daycnt % 7);
    }

private:
    int getdaycnt(int month, int day, bool isrun) {
        int res = 0;
        for (int i = 1; i < month; ++i) {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                res += 31;
            else if (i == 2)
                res += isrun ? 29 : 28;
            else
                res += 30;
        }
        res += day;
        return res;
    }

    string dateOf(int num) {
//        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
        switch (num) {
            case 0:
                return "Friday";
                break;
            case 1:
                return "Saturday";
                break;
            case 2:
                return "Sunday";
                break;
            case 3:
                return "Monday";
                break;
            case 4:
                return "Tuesday";
                break;
            case 5:
                return "Wednesday";
                break;
            case 6:
                return "Thursday";
                break;
        }
        return "Unkonw";
    }
};


int main() {
    Solution sol = Solution();
    int d, m, y;
    while (cin >> d >> m >> y) {
        cout << sol.dayOfTheWeek(d, m, y) << endl;
    }
    return 0;
}
