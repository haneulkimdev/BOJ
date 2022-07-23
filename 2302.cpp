// http://boj.kr/a6906aa1bf434e5c9d954422d2affb76
#include <bits/stdc++.h>
using namespace std;

int d[41];
int fix[42];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n;
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> fix[i];
  fix[m + 1] = n + 1;
  d[0] = 1;
  d[1] = 1;
  for (int i = 2; i <= n; i++) d[i] = d[i - 1] + d[i - 2];
  int ans = 1;
  for (int i = 1; i <= m + 1; i++) ans *= d[fix[i] - fix[i - 1] - 1];
  cout << ans;
}