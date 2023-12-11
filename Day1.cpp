#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

  ifstream infile("input_1_.txt");
  string line;
  int total = 0;
  while (getline(infile, line))
  {
    cout << line.length() << endl;
    string lower;
    string upper;
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
          cout << isdigit(line[i]);
          for (int j = 0; j < i; j++)
          {

            if (find(vec.begin(), vec.end(), line.substr(j, i)) != vec.end())
            {

              lower = mp[line.substr(j, i)];

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
            cout << "output:" << number_to_add << endl;
            total += number_to_add;
          }
        }
      }
    }
  }
  cout << total << endl;
  return 0;
}
