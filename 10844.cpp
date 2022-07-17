// http://boj.kr/0cc30c7ac1704911a00da603cdcc9848
#include <bits/stdc++.h>
using namespace std;

int d[101][10];
int mod = 1000000000;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < 10; i++) d[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      if (j > 0) d[i][j] += d[i - 1][j - 1];
      if (j < 9) d[i][j] += d[i - 1][j + 1];
      d[i][j] %= mod;
    }
  }
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    ans += d[n][i];
    ans %= mod;
  }
  cout << ans;
}