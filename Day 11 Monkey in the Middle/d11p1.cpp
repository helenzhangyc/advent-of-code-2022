#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<string> split_str(string s, char delimiter)
{
    stringstream ss(s);
    vector<string> result;

    while (ss.good())
    {
        string substr;
        getline(ss, substr, delimiter);
        result.push_back(substr);
    }
    return result;
}

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        // stores the worry levels of the items a monkey holds
        vector<vector<int>> monkey;
        // stores the number of inspections for each monkey
        vector<int> inspect_count;
        vector<int> empty;
        vector<string> empty_str;
        vector<vector<string>> operation_list;
        vector<int> divisor_list;
        vector<int> true_list;
        vector<int> false_list;
        for (int i = 0; i <= 7; ++i)
        {
            monkey.push_back(empty);
            inspect_count.push_back(0);
            divisor_list.push_back(0);
            operation_list.push_back(empty_str);
            true_list.push_back(0);
            false_list.push_back(0);
        }
        int current_monkey = -1;
        while (getline(newfile, line))
        {
            if (line.find("Monkey") != string::npos)
            {
                current_monkey++;
            }
            else if (line.find("Starting items") != string::npos)
            {
                line = line.substr(line.find(":") + 1);
                vector<string> starting_items = split_str(line, ',');
                int num_items = starting_items.size();
                for (int i = 0; i < num_items; ++i)
                {
                    monkey[current_monkey].push_back(stoi(starting_items[i]));
                }
            }
            else if (line.find("Operation:") != string::npos)
            {
                line = line.substr(line.find(":") + 1);
                vector<string> operation = split_str(split_str(line, '=')[1], ' ');
                for (int i = 1; i <= 3; ++i)
                {
                    operation_list[current_monkey].push_back(operation[i]);
                }
            }
            else if (line.find("Test") != string::npos)
            {
                vector<string> line_split = split_str(line, ' ');
                int length = line_split.size();
                int divisor = stoi(line_split[length - 1]);
                divisor_list[current_monkey] = divisor;
            }
            else if (line.find("true") != string::npos)
            {
                vector<string> line_split = split_str(line, ' ');
                int length = line_split.size();
                int monkey_throw_to = stoi(line_split[length - 1]);
                true_list[current_monkey] = monkey_throw_to;
            }
            else if (line.find("false") != string::npos)
            {
                vector<string> line_split = split_str(line, ' ');
                int length = line_split.size();
                int monkey_throw_to = stoi(line_split[length - 1]);
                false_list[current_monkey] = monkey_throw_to;
            }
        }
        for (int round = 1; round <= 20; ++round)
        {
            for (int m = 0; m <= 7; ++m)
            {
                // check every item of the monkey and process them
                for (int j = 0; j < monkey[m].size(); ++j)
                {
                    int worry = monkey[m][j];
                    // update inspect count for that monkey
                    inspect_count[m]++;
                    // perform operation_list[m] on worry
                    string curr_operator = operation_list[m][1];
                    string operand = operation_list[m][2];
                    int number = 0;
                    if (operand != "old")
                    {
                        number = stoi(operand);
                        if (curr_operator == "+")
                        {
                            worry += number;
                        }
                        else if (curr_operator == "*")
                        {
                            worry *= number;
                        }
                    }
                    else
                    {
                        worry = worry * worry;
                    }
                    // monkey gets bored. Divide worry level by 3
                    worry /= 3;
                    // throw item to intended monkey
                    if (worry % divisor_list[m] == 0)
                    {
                        // throw to true_list[m]
                        // remove item from monkey m
                        monkey[m].erase(monkey[m].begin());
                        j--;
                        // add item to the new monkey
                        monkey[true_list[m]].push_back(worry);
                    }
                    else
                    {
                        // throw to false_list[m]
                        // remove item from monkey m
                        monkey[m].erase(monkey[m].begin());
                        j--;
                        // add item to the new monkey
                        monkey[false_list[m]].push_back(worry);
                    }
                }
            }
        }
        // find the top two number from inspect_count and multiply them together
        int first_active = 0;
        int second_active = 0;
        for (auto i : inspect_count)
        {
            if (i >= first_active)
            {
                second_active = first_active;
                first_active = i;
            }
            else if (i >= second_active)
            {
                second_active = i;
            }
        }
        cout << first_active * second_active << endl;
    }
    newfile.close();

    return 0;
}