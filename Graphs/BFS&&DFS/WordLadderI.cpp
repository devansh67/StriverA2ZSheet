#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

// https://leetcode.com/problems/word-ladder/description/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        set<string> s;
        int answer = 0;

        for (auto it : wordList)
        {
            s.insert(it);
        }

        if (s.find(endWord) == s.end())
        {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        if (s.find(beginWord) != s.end())
        {
            s.erase(beginWord);
        }

        while (!q.empty())
        {
            auto presentWord = q.front();
            q.pop();
            string word = presentWord.first;
            int cost = presentWord.second;

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if (ch == original)
                        continue;
                    word[i] = ch;

                    if (word == endWord)
                        return cost + 1;

                    if (s.find(word) != s.end())
                    {
                        q.push({word, cost + 1});
                        s.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        return answer;
    }
};