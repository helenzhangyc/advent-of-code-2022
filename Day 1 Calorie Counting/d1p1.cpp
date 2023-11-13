// calorie counting
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open()) {
        int currMax = 0;
        string currCalorie;
        vector<int> elf;
        while (getline(newfile, currCalorie)) {
            if (currCalorie == "") {
                int sum = accumulate(elf.begin(), elf.end(), 0);
                if (sum > currMax) {
                    currMax = sum;
                }
                elf.clear();
            } else {
                elf.emplace_back(stoi(currCalorie));
            }
        }
        cout << currMax << endl;
    }
    newfile.close(); 
    return 0;
}