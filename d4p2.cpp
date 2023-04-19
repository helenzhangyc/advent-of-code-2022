// --- Day 4: Camp Cleanup ---
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

vector<string> splitString(string str, char delimeter) {
    stringstream ss(str);
    string segment;
    vector<string> seglist;
    while (getline(ss, segment, delimeter)) {
        seglist.emplace_back(segment);
    }
    return seglist;
}

int main() {
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open()) {
        int sum = 0;
        string line;
        while (getline(newfile, line)) {
            vector<string> tmp = splitString(line, ',');
            string firstElfRange = tmp[0];
            string secondElfRange = tmp[1];
            vector<string> tmp1 = splitString(firstElfRange, '-');
            int firstElfLo = stoi(tmp1[0]);
            int firstElfHi = stoi(tmp1[1]);
            vector<string> tmp2 = splitString(secondElfRange, '-');
            int secondElfLo = stoi(tmp2[0]);
            int secondElfHi = stoi(tmp2[1]);
            if ((firstElfHi >= secondElfLo && (!(firstElfLo > secondElfHi))) ||
             (secondElfHi >= firstElfLo && (!(secondElfLo > firstElfHi)))) {
                ++sum;
            }
        }
        cout << sum << endl;
    }
    newfile.close();
    return 0;
}