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

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        int cycle = 0;
        int x = 1;
        vector<char> crt;
        for (int i = 0; i < 240; ++i)
        {
            crt.push_back('.');
        }
        while (getline(newfile, line))
        {
            if (line.substr(0, 4) == "noop")
            {
                cycle++;
                if ((cycle - 1) % 40 == x || (cycle - 1) % 40 == x - 1 || (cycle - 1) % 40 == x + 1)
                {
                    crt[cycle - 1] = '#';
                }
            }
            else if (line.substr(0, 4) == "addx")
            {
                for (int i = 0; i < 2; ++i)
                {
                    cycle++;
                    if ((cycle - 1) % 40 == x || (cycle - 1) % 40 == x - 1 || (cycle - 1) % 40 == x + 1)
                    {
                        crt[cycle - 1] = '#';
                    }
                }
                x += stoi(split_str(line)[1]);
            }
        }
        for (int i = 0; i < 240; ++i)
        {
            if (i % 40 == 0)
            {
                cout << endl;
            }
            cout << crt[i];
        }
    }
    newfile.close();

    return 0;
}