// --- Day 6: Tuning Trouble ---
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open()) {
        string line;
        while (getline(newfile, line)) {
            int len = line.length();
            bool flag = true;
            for (int i = 0; i < len - 14; ++i) {
                flag = true;
                string substr = line.substr(i, 14);
                for (int j = 0; j < 14; ++j) {
                    for (int k = j + 1; k < 14; ++k) {
                        if (substr[j] == substr[k]) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    cout << i + 14 << endl;
                    exit(0);
                }
            }
        }
       
    }
    newfile.close();
  
    return 0;
}