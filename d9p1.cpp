// Day 9: Rope Bridge
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<string> splitStr(string s)
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

// check if t is in range of h
bool inRange(int h_x, int h_y, int t_x, int t_y)
{
    if (abs(h_x - t_x) <= 1 && abs(h_y - t_y) <= 1)
    {
        return true;
    }
    return false;
}

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        // create a grid of side length 100
        vector<vector<bool>> visited;
        vector<bool> tmp;
        for (int i = 0; i < 1000; ++i)
        {
            tmp.push_back(false);
        }
        for (int i = 0; i < 1000; ++i)
        {
            visited.push_back(tmp);
        }
        int h_x = 500;
        int h_y = 500;
        int t_x = 500;
        int t_y = 500;
        // starting point
        visited[500][500] = true;
        while (getline(newfile, line))
        {
            vector<string> split = splitStr(line);
            string direction = split[0];
            int num = stoi(split[1]);
            // left
            if (direction == "L")
            {
                for (int i = 0; i < num; ++i)
                {
                    h_y--;
                    if (!inRange(h_x, h_y, t_x, t_y))
                    {
                        t_y--;
                        if (h_x == t_x - 1)
                        {
                            t_x--;
                        }
                        else if (h_x == t_x + 1)
                        {
                            t_x++;
                        }
                        visited[t_x][t_y] = true;
                    }
                }
            }
            else if (direction == "R")
            {
                for (int i = 0; i < num; ++i)
                {
                    h_y++;
                    if (!inRange(h_x, h_y, t_x, t_y))
                    {
                        t_y++;
                        if (h_x == t_x - 1)
                        {
                            t_x--;
                        }
                        else if (h_x == t_x + 1)
                        {
                            t_x++;
                        }
                        visited[t_x][t_y] = true;
                    }
                }
            }
            else if (direction == "U")
            {
                for (int i = 0; i < num; ++i)
                {
                    h_x--;
                    if (!inRange(h_x, h_y, t_x, t_y))
                    {
                        t_x--;
                        if (h_y == t_y - 1)
                        {
                            t_y--;
                        }
                        else if (h_y == t_y + 1)
                        {
                            t_y++;
                        }
                        visited[t_x][t_y] = true;
                    }
                }
            }
            else if (direction == "D")
            {
                for (int i = 0; i < num; ++i)
                {
                    h_x++;
                    if (!inRange(h_x, h_y, t_x, t_y))
                    {
                        t_x++;
                        if (h_y == t_y - 1)
                        {
                            t_y--;
                        }
                        else if (h_y == t_y + 1)
                        {
                            t_y++;
                        }
                        visited[t_x][t_y] = true;
                    }
                }
            }
        }
        // count number of true in visited
        int count = 0;
        for (int r = 0; r < 1000; ++r)
        {
            for (int c = 0; c < 1000; ++c)
            {
                if (visited[r][c])
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