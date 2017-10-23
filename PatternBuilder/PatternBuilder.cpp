#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string GetFinalPattern(vector<string> vStrings)
{
  if (vStrings.empty()) return "";

  string result = vStrings[0];

  for each(string temp_str in vStrings)
  {
    for (int i = 0; i < (int)temp_str.length(); i++)
    {
      if (result[i] != temp_str[i])
      {
        result[i] = '?';
      }
    }
  }

  return result;
}

int main()
{
  ifstream input_file("patterns.txt");

  vector<string> vStrings;
  
  if (input_file.is_open())
  {
    string temp_str;
    while (getline(input_file, temp_str))
    {
      vStrings.push_back(temp_str);
    }
    input_file.close();
  }
  else
  {
    cout << "Error open input file!" << endl;
  }

  if (!vStrings.empty())
  {
    string result = GetFinalPattern(vStrings);
    cout << result << endl;

    ofstream output_file("result.txt");

    if (output_file.is_open())
    {
      output_file << result;
      output_file.close();
    }
    else
    {
      cout << "Error open output file!" << endl;
    }
  }

  system("pause");

  return 0;
}

