// http://boj.kr/d4821353bb5d4a16b027b1a432d21885
#include <bits/stdc++.h>
using namespace std;

int d[1001][10];
int mod = 10007;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 10; i++) d[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k <= j; k++) {
        d[i][j] += d[i - 1][k];
        d[i][j] %= mod;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    ans += d[n][i];
    ans %= mod;
  }
  cout << ans;
}