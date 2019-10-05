//
//  main.cpp
//  355. Design Twitter
//
//  Created by 边俊林 on 2019/10/4.
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
class Twitter {
public:
    Twitter() { }

    void postTweet(int userId, int tweetId) {
        if (users.count(userId) <= 0) {
            users[userId] = User();
        }
        users[userId].feeds.insert(make_pair(_postId++, tweetId));
    }

    vector<int> getNewsFeed(int userId) {
        if (users.count(userId) <= 0) return {};
        User user = users[userId];
        auto followees = user.followee;
        followees.insert(userId);
        vector<pair<int, int>> allfeeds;
        for (auto& followee: followees) {
            auto curfeed = users[followee].feeds;
            allfeeds.insert(allfeeds.end(), curfeed.begin(), curfeed.end());
        }
        int resSz = min((int)allfeeds.size(), 10);
        auto cmp = [](pair<int, int>& a, pair<int, int>& b){ return a.first >= b.first; };
        partial_sort(allfeeds.begin(), allfeeds.begin()+resSz, allfeeds.end(), cmp);
        vector<int> res (resSz);
        for (int i = 0; i < resSz; ++i)
            res[i] = allfeeds[i].second;
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (users.count(followerId) <= 0) {
            users[followerId] = User();
        }
        users[followerId].followee.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (users.count(followerId) <= 0) {
            users[followerId] = User();
        }
        users[followerId].followee.erase(followeeId);
    }

    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };

private:
    struct User {
        User() { }
        unordered_set<pair<int, int>, pair_hash> feeds;
        unordered_set<int> followee;
    };
    unordered_map<int, User> users;
    int _postId = 0;
};

int main() {
//    Twitter sol = Twitter();
//    sol.postTweet(1, 5);
//    auto feeds1 = sol.getNewsFeed(1);
//    sol.follow(1, 2);
//    sol.postTweet(2, 6);
//    auto feeds2 = sol.getNewsFeed(1);
//    sol.unfollow(1, 2);
//    auto feeds3 = sol.getNewsFeed(1);

//    Twitter sol = Twitter();
//    sol.postTweet(1, 1);
//    auto feeds1 = sol.getNewsFeed(1);
//    sol.follow(2, 1);
//    auto feeds2 = sol.getNewsFeed(2);
//    sol.unfollow(2, 1);
//    auto feeds3 = sol.getNewsFeed(2);

    Twitter sol = Twitter();
    sol.postTweet(1, 5);
    sol.postTweet(1, 3);
    auto feeds1 = sol.getNewsFeed(1);

    return 0;
}
