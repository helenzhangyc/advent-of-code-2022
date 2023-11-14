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
        int sum = 0;
        while (getline(newfile, line))
        {

            set<int> signal_check = {20, 60, 100, 140, 180, 220};
            if (line.substr(0, 4) == "noop")
            {
                cycle++;
                if (signal_check.find(cycle) != signal_check.end())
                {
                    sum += cycle * x;
                }
            }
            else if (line.substr(0, 4) == "addx")
            {
                for (int i = 0; i < 2; ++i)
                {
                    cycle++;
                    if (signal_check.find(cycle) != signal_check.end())
                    {
                        sum += cycle * x;
                    }
                }
                x += stoi(split_str(line)[1]);
            }
        }
        cout << sum << endl;
    }
    newfile.close();

    return 0;
}