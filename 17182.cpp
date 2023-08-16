// http://boj.kr/44f18f71a57e4f1db302db7b31d3045e
#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[10][10];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> d[i][j];
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  vector<int> brute;
  for (int i = 0; i < n; i++)
    if (i != k) brute.push_back(i);
  int ans = 0x7fffffff;
  do {
    int sum = d[k][brute[0]];
    for (int i = 1; i < n - 1; i++) sum += d[brute[i - 1]][brute[i]];
    ans = min(ans, sum);
  } while (next_permutation(brute.begin(), brute.end()));
  cout << ans;
}