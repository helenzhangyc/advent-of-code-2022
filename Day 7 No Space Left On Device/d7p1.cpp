
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<string> split_str(string s)
{
    vector<string> v;
    int start = 0;
    int end = 0;
    char dl = ' ';
    while ((start = s.find_first_not_of(dl, end)) != string::npos)
    {
        end = s.find(dl, start);
        v.push_back(s.substr(start, end - start));
    }
    return v;
}

int index_of_last_backslash(string s)
{
    int length = s.length();
    for (int i = length - 1; i >= 0; --i)
    {
        if (s[i] == '/')
        {
            return i;
        }
    }
    return length;
}

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        map<string, int> directories;
        directories.insert({"/home", 0});
        string current_path = "";
        string line;
        while (getline(newfile, line))
        {
            vector<string> line_split = split_str(line);
            if (line_split[0] == "$")
            {
                if (line_split[1] == "ls")
                {
                    continue;
                }
                else
                {
                    if (line_split[2] == "..")
                    {
                        int index = index_of_last_backslash(current_path);
                        current_path = current_path.substr(0, index);
                    }
                    else if (line_split[2] == "/")
                    {
                        current_path = "/home";
                    }
                    else
                    {
                        current_path = current_path + "/" + line_split[2];
                        directories[current_path] = 0;
                    }
                }
            }
            else
            {
                if (line_split[0] != "dir")
                {
                    string tmp_path = current_path;
                    while (tmp_path != "")
                    {
                        directories[tmp_path] += stoi(line_split[0]);
                        int index = index_of_last_backslash(tmp_path);
                        tmp_path = tmp_path.substr(0, index);
                    }
                }
            }
        }
        int sum_directories = 0;
        for (auto const &[key, val] : directories)
        {
            if (val <= 100000)
            {
                sum_directories += val;
            }
        }
        cout << sum_directories << endl;
    }
    newfile.close();

    return 0;
}