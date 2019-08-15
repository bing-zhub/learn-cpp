#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m, cup[N], pro[N], ans;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> cup[i];
  cin >> m;
  for (int i = 0; i < m; i++)
    cin >> pro[i];
  sort(cup, cup + n);
  sort(pro, pro + m);
  int i = 0, j = 0;
  while (i < n && j < m && cup[i] < 0 && pro[j] < 0)
    ans += cup[i++] * pro[j++];
  i = n - 1, j = m - 1;
  while (i >= 0 && j >= 0 && cup[i] > 0 && pro[j] > 0)
    ans += cup[i--] * pro[j--];
  cout << ans;
  return 0;
}