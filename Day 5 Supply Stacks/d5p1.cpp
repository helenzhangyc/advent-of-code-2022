// --- Day 5: Supply Stacks ---
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
#include <regex>
#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream newfile;
    newfile.open("input.txt", ios::in);

    // initialize the array of stacks
    vector<stack<char>> s;
    stack<char> tmp;
    for (int i = 0; i < 9; ++i) {
        s.emplace_back(tmp);
    }

    vector<vector<char>> v;
    vector<char> tmp2;
    for (int i = 0; i < 9; ++i) {
        v.emplace_back(tmp2);
    }

    if (newfile.is_open()) {
        string line;
        while (getline(newfile, line) && line.find("[") != string::npos) {
                int len = line.length();
                for (int i = 0; i < len; ++i) {
                    if (line[i] >= 65 && line[i] <= 90) {
                        int idx = (i - 1) / 4;
                        v[idx].emplace_back(line[i]);
                    }
                }
        }
        for (int i = 0; i < 9; ++i) {
            vector<char> tmp = v[i];
            for (int j = tmp.size() - 1; j >= 0; --j) {
                s[i].push(tmp[j]);
            }
        }
        while (getline(newfile, line)) {
            if (line.find("move") != string::npos) {
                line = regex_replace(line, regex("move "), "");
                line = regex_replace(line, regex("from "), "");
                line = regex_replace(line, regex("to "), "");
                stringstream ss(line);
                string tmp;
                ss >> tmp;
                int numToMove = stoi(tmp);
                ss >> tmp;
                int from = stoi(tmp);
                ss >> tmp;
                int to = stoi(tmp);
                for (int i = 0; i < numToMove; ++i) {
                    char top = s[from - 1].top();
                    s[from - 1].pop();
                    s[to - 1].push(top);
                }
            }
        }
    }
    newfile.close();
    for (int i = 0; i < 9; ++i) {
        cout << s[i].top();
    }
    return 0;
}