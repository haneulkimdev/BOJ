// http://boj.kr/42236c2b46224fa8b3c6f8a3c6201203
#include <bits/stdc++.h>
using namespace std;

int d[301][301];
int n, m, t;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    fill(d[i] + 1, d[i] + n + 1, 0x7fffffff);
    d[i][i] = 0;
  }
  while (m--) {
    int u, v, h;
    cin >> u >> v >> h;
    d[u][v] = h;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
  while (t--) {
    int s, e;
    cin >> s >> e;
    if (d[s][e] == 0x7fffffff)
      cout << -1 << '\n';
    else
      cout << d[s][e] << '\n';
  }
}