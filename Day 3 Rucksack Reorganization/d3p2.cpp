// Rucksack Reorganization
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open()) {
        int sum = 0;
        string line1;
        string line2;
        string line3;
        while (getline(newfile, line1)) {
            getline(newfile, line2);
            getline(newfile, line3);
            int len = line1.length();
            for (int i = 0; i < len; ++i) {
                if (line2.find(line1[i]) != string::npos
                 && line3.find(line1[i]) != string::npos) {
                    char target =  line1[i];
                    cout << target << endl;
                    if ('a' <= target && target <= 'z') {
                        sum += target - 96;
                    } else {
                        sum += target - 38;
                    }
                    break;
                }
                
            }
        }
        cout << sum << endl;
    }
    newfile.close();
    return 0;
}