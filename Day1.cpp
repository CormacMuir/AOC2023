#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool isNum(string);
int main()
{
  vector<string> vec = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  map<string, int> mp;
  mp["one"] = '1';
  mp["two"] = '2';
  mp["three"] = '3';
  mp["four"] = '4';
  mp["five"] = '5';
  mp["six"] = '6';
  mp["seven"] = '7';
  mp["eight"] = '8';
  mp["nine"] = '9';

  ifstream infile("input_1.txt");
  string line;
  int total = 0;
  while (getline(infile, line))
  {
    string lower;
    string upper;
    if(isNum(line)){
      lower = line[0];
      upper = line[line.length()-1];
      int number_to_add = stoi(lower + upper);
      cout << line <<" Produces: "<< number_to_add << endl;
      total += number_to_add;
    }else{
    for (int i = 0; i < line.length(); i++)
    {
      {
        if (isdigit(line[i]))
        {

          lower = line[i];

          i = line.length() + 1;
        }
        else
        {
          for (int j = 0; j < i; j++)
          {
            if (find(vec.begin(), vec.end(), line.substr(j, i+1)) != vec.end())
            {

              lower = mp[line.substr(j, i+1)];

              i = line.length();
              j = i + 1;
            }
          }
        }
      }
    }

    for (int i = line.length() - 1; i >= 0; i--)
    {
      if (isdigit(line[i]))
      {
        upper = line[i];

        i = -1;
        int number_to_add = stoi(lower + upper);

        total += number_to_add;
      }
      else
      {
        string sub = line.substr(i, line.length() - 1);

        for (int j = 0; j < sub.length(); j++)
        {

          if (find(vec.begin(), vec.end(), sub.substr(0, j + 1)) != vec.end())
          {

            upper = mp[sub.substr(0, j + 1)];

            i = -1;
            j = 999;

            int number_to_add = stoi(lower + upper);
            cout << line <<" Produces: "<< number_to_add << endl;
            total += number_to_add;
          }
        }
      }
    }
    }
  }
  cout << total << endl;
  return 0;
}

bool isNum(string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}