#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define R 41
#define C 144

// store current location and distance from S
class Info
{
public:
    int row;
    int col;
    int dist;
    Info(int x, int y, int w)
        : row(x), col(y), dist(w)
    {
    }
};

// bfs
int bfs(vector<vector<char>> grid, int s_r, int s_c, int e_r, int e_c)
{
    Info source(s_r, s_c, 0);
    bool visited[R][C];
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            visited[i][j] = false;
        }
    }
    queue<Info> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while (!q.empty())
    {
        Info p = q.front();
        q.pop();

        if (p.row == e_r && p.col == e_c)
        {
            return p.dist;
        }

        // up
        if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false && grid[p.row - 1][p.col] <= grid[p.row][p.col] + 1)
        {
            q.push(Info(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }

        // down
        if (p.row + 1 < R && visited[p.row + 1][p.col] == false && grid[p.row + 1][p.col] <= grid[p.row][p.col] + 1)
        {
            q.push(Info(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }

        // left
        if (p.col - 1 >= 0 && visited[p.row][p.col - 1] == false && grid[p.row][p.col - 1] <= grid[p.row][p.col] + 1)
        {
            q.push(Info(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }

        // right
        if (p.col + 1 < C && visited[p.row][p.col + 1] == false && grid[p.row][p.col + 1] <= grid[p.row][p.col] + 1)
        {
            q.push(Info(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }
    }
    return -1;
}

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    vector<vector<char>> grid;
    if (newfile.is_open())
    {
        string line;

        while (getline(newfile, line))
        {
            vector<char> tmp;
            for (int i = 0; i < C; ++i)
            {
                tmp.push_back(line[i]);
            }
            grid.push_back(tmp);
        }
    }
    // process grid
    // find S and E
    int s_r = 0;
    int s_c = 0;
    int e_r = 0;
    int e_c = 0;
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            if (grid[r][c] == 'S')
            {
                s_r = r;
                s_c = c;
                grid[r][c] = 'a';
            }
            if (grid[r][c] == 'E')
            {
                e_r = r;
                e_c = c;
                grid[r][c] = 'z';
            }
        }
    }
    cout << bfs(grid, s_r, s_c, e_r, e_c) << endl;
    return 0;
}