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
        int first = 0;
        int second = 0;
        int third = 0;
        string currCalorie;
        vector<int> elf;
        while (getline(newfile, currCalorie)) {
            if (currCalorie == "") {
                int sum = accumulate(elf.begin(), elf.end(), 0);
                if (sum > first) {
                    third = second;
                    second = first;
                    first = sum;
                } else if (sum > second) {
                    third = second;
                    second = sum;
                } else if (sum > third) {
                    third = sum;
                }
                elf.clear();
            } else {
                elf.emplace_back(stoi(currCalorie));
            }
        }
        cout << first + second + third << endl;
    }
    newfile.close(); 
    return 0;
}