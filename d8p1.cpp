// Day 8: Treetop Tree House
// --- Day 6: Tuning Trouble ---
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
        int count = 0;
        for (int r = 0; r < side_length; ++r)
        {
            for (int c = 0; c < side_length; ++c)
            {
                bool isVisible = true;
                for (int i = 0; i < r; ++i)
                {
                    if (grid[i][c] >= grid[r][c])
                    {
                        isVisible = false;
                        break;
                    }
                }
                if (isVisible)
                {
                    count++;
                }
                else
                {
                    isVisible = true;
                    for (int i = r + 1; i < side_length; ++i)
                    {
                        if (grid[i][c] >= grid[r][c])
                        {
                            isVisible = false;
                            break;
                        }
                    }
                    if (isVisible)
                    {
                        count++;
                    }
                    else
                    {
                        isVisible = true;
                        for (int i = 0; i < c; ++i)
                        {
                            if (grid[r][i] >= grid[r][c])
                            {
                                isVisible = false;
                                break;
                            }
                        }
                        if (isVisible)
                        {
                            count++;
                        }
                        else
                        {
                            isVisible = true;
                            for (int i = c + 1; i < side_length; ++i)
                            {
                                if (grid[r][i] >= grid[r][c])
                                {
                                    isVisible = false;
                                    break;
                                }
                            }
                            if (isVisible)
                            {
                                count++;
                            }
                        }
                    }
                }
            }
        }
        cout << count << endl;
    }

    newfile.close();

    return 0;
}