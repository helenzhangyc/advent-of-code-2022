// Rock Paper Scissors
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int main() {
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open()) {
        int score = 0;
        string tmp;
        while (getline(newfile, tmp)) {
            stringstream ss(tmp);
            string elfPlay;
            string myPlay;
            ss >> elfPlay;
            ss >> myPlay;
            if (elfPlay == "A" && myPlay == "X") {
                score += 1 + 3;
            } else if (elfPlay == "A" && myPlay == "Y") {
                score += 2 + 6;
            } else if (elfPlay == "A" && myPlay == "Z") {
                score += 3 + 0;
            } else if (elfPlay == "B" && myPlay == "X") {
                score += 1 + 0;
            } else if (elfPlay == "B" && myPlay == "Y") {
                score += 2 + 3;
            } else if (elfPlay == "B" && myPlay == "Z") {
                score += 3 + 6;
            } else if (elfPlay == "C" && myPlay == "X") {
                score += 1 + 6;
            } else if (elfPlay == "C" && myPlay == "Y") {
                score += 2 + 0;
            } else if (elfPlay == "C" && myPlay == "Z") {
                score += 3 + 3;
            }
        }
        cout << score;
    }
    newfile.close();
    return 0;
}