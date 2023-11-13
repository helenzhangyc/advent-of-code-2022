// Day 9: Rope Bridge
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<string> split_str(string s)
{
    vector<string> retval;
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        retval.push_back(word);
    }
    return retval;
}

bool inRange(pair<int, int> head, pair<int, int> tail)
{
    return abs(head.first - tail.first) <= 1 && abs(head.second - tail.second) <= 1;
}

pair<int, int> move_rope(pair<int, int> head, pair<int, int> tail)
{
    // head and tail are on the same column
    if (head.second == tail.second)
    {
        if (head.first < tail.first)
        {
            while (!inRange(head, tail))
            {
                tail.first--;
            }
            return tail;
        }
        if (head.first > tail.first)
        {
            while (!inRange(head, tail))
            {
                tail.first++;
            }
            return tail;
        }
    } // head and tail are on the same row
    else if (head.first == tail.first)
    {
        if (head.second < tail.second)
        {
            while (!inRange(head, tail))
            {
                tail.second--;
            }
            return tail;
        }
        if (head.second > tail.second)
        {
            while (!inRange(head, tail))
            {
                tail.second++;
            }
            return tail;
        }
    }
    // <<
    else if (head.first < tail.first && head.second < tail.second)
    {
        while (!inRange(head, tail))
        {
            tail.first--;
            tail.second--;
        }
        return tail;
    }
    // <>
    else if (head.first < tail.first && head.second > tail.second)
    {
        while (!inRange(head, tail))
        {
            tail.first--;
            tail.second++;
        }
        return tail;
    }
    // ><
    else if (head.first > tail.first && head.second < tail.second)
    {
        while (!inRange(head, tail))
        {
            tail.first++;
            tail.second--;
        }
        return tail;
    }
    // >>
    else if (head.first > tail.first && head.second > tail.second)
    {
        while (!inRange(head, tail))
        {
            tail.first++;
            tail.second++;
        }
        return tail;
    }
}

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        // create a grid of side length 90
        vector<vector<bool>> visited;
        vector<bool> tmp;
        for (int i = 0; i < 5000; ++i)
        {
            tmp.push_back(false);
        }
        for (int i = 0; i < 5000; ++i)
        {
            visited.push_back(tmp);
        }
        vector<pair<int, int>> rope;
        for (int i = 0; i < 10; ++i)
        {
            rope.push_back(make_pair(2500, 2500));
        }
        while (getline(newfile, line))
        {
            vector<string> split = split_str(line);
            string direction = split[0];
            int num = stoi(split[1]);
            if (direction == "L")
            {
                for (int j = 0; j < num; ++j)
                {
                    rope[0].second--;
                    for (int i = 0; i <= 8; ++i)
                    {
                        if (!inRange(rope[i], rope[i + 1]))
                        {
                            rope[i + 1] = move_rope(rope[i], rope[i + 1]);
                        }
                    }
                    visited[rope[9].first][rope[9].second] = true;
                }
            }
            else if (direction == "R")
            {
                for (int j = 0; j < num; ++j)
                {
                    rope[0].second++;
                    for (int i = 0; i <= 8; ++i)
                    {
                        if (!inRange(rope[i], rope[i + 1]))
                        {
                            rope[i + 1] = move_rope(rope[i], rope[i + 1]);
                        }
                    }
                    visited[rope[9].first][rope[9].second] = true;
                }
            }
            else if (direction == "U")
            {
                for (int j = 0; j < num; ++j)
                {
                    rope[0].first--;
                    for (int i = 0; i <= 8; ++i)
                    {
                        if (!inRange(rope[i], rope[i + 1]))
                        {
                            rope[i + 1] = move_rope(rope[i], rope[i + 1]);
                        }
                    }
                    visited[rope[9].first][rope[9].second] = true;
                }
            }
            else if (direction == "D")
            {
                for (int j = 0; j < num; ++j)
                {
                    rope[0].first++;
                    for (int i = 0; i <= 8; ++i)
                    {
                        if (!inRange(rope[i], rope[i + 1]))
                        {
                            rope[i + 1] = move_rope(rope[i], rope[i + 1]);
                        }
                    }
                    visited[rope[9].first][rope[9].second] = true;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < 5000; ++i)
        {
            for (int j = 0; j < 5000; ++j)
            {
                if (visited[i][j])
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    newfile.close();

    return 0;
}