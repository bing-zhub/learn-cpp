#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string map[10] = {"zero", "one", "two",   "three", "four",
                  "five", "six", "seven", "eight", "nine"};
int sum;

int main() {
  vector<int> res;
  string in;
  cin >> in;
  for (int i = in.size() - 1; i >= 0; i--)
    sum += in[i] - '0';
  while (sum > 0)
    res.push_back(sum % 10), sum /= 10;
  if (in != "0") {
    reverse(res.begin(), res.end());
    cout << map[res[0]];
    for (int i = 1; i < res.size(); i++)
      cout << " " << map[res[i]];
  } else
    cout << "zero";

  return 0;
}