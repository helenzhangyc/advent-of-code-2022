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
        string line;
        while (getline(newfile, line)) {
            int len = line.length();
            int lenCompartment = len / 2;
            string firstPart = line.substr(0, lenCompartment);
            string secondPart = line.substr(lenCompartment, lenCompartment);
            for (int i = 0; i < lenCompartment; ++i) {
                if (secondPart.find(firstPart[i]) != string::npos) {
                    char target =  firstPart[i];
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