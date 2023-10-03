// Day 8: Treetop Tree House
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        vector<vector<int>> grid;
        while (getline(newfile, line))
        {
            vector<int> row;
            int len = line.length();
            for (int i = 0; i < len; ++i)
            {
                row.push_back(int(line.at(i)));
            }
            grid.push_back(row);
        }
        int side_length = grid.size();
        int curr_max = 0;
        for (int r = 1; r < side_length - 1; ++r)
        {
            for (int c = 1; c < side_length - 1; ++c)
            {
                int score = 1;
                // left
                int count = 0;
                for (int i = c - 1; i >= 0; --i)
                {
                    count++;
                    if (grid[r][i] >= grid[r][c])
                    {
                        break;
                    }
                }
                score *= count;
                // right
                count = 0;
                for (int i = c + 1; i <= side_length - 1; ++i)
                {
                    count++;
                    if (grid[r][i] >= grid[r][c])
                    {
                        break;
                    }
                }
                score *= count;
                // up
                count = 0;
                for (int i = r - 1; i >= 0; --i)
                {
                    count++;
                    if (grid[i][c] >= grid[r][c])
                    {
                        break;
                    }
                }
                score *= count;
                // down
                count = 0;
                for (int i = r + 1; i <= side_length - 1; ++i)
                {
                    count++;
                    if (grid[i][c] >= grid[r][c])
                    {
                        break;
                    }
                }
                score *= count;
                if (score > curr_max)
                {
                    curr_max = score;
                }
            }
        }
        cout << curr_max << endl;
    }

    newfile.close();

    return 0;
}