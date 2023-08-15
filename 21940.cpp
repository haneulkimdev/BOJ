// http://boj.kr/72f2c79bf4344f83b7589d2c7fffe851
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int d[201][201];
int c[201];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fill(d[i] + 1, d[i] + n + 1, 0x3fffffff);
    d[i][i] = 0;
  }
  while (m--) {
    int a, b, t;
    cin >> a >> b >> t;
    d[a][b] = t;
  }
  cin >> k;
  for (int i = 0; i < k; i++) cin >> c[i];
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  int mn = 0x7fffffff;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 0; j < k; j++) mx = max(mx, d[c[j]][i] + d[i][c[j]]);
    if (mx <= mn) {
      if (mx < mn) ans.clear();
      ans.push_back(i);
      mn = mx;
    }
  }
  sort(ans.begin(), ans.end());
  for (auto x : ans) cout << x << ' ';
}