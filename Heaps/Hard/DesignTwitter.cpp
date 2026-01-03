#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/design-twitter/description/

class Twitter
{
private:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int time;

public:
    Twitter()
    { 
        time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        vector<int> answer;

        for (auto it : tweets[userId])
        {
            pq.push(it);

            if (pq.size() > 10)
            {
                pq.pop();
            }
        }

        for (auto followee : following[userId])
        {
            for (auto it : tweets[followee])
            {
                pq.push(it);

                if (pq.size() > 10)
                {
                    pq.pop();
                }
            }
        }

        while (!pq.empty())
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }

    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};