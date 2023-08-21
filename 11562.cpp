// http://boj.kr/70ee49e8b5cc43878d620d86754c101e
#include <bits/stdc++.h>
using namespace std;

int d[251][251];
int n, m, k;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fill(d[i] + 1, d[i] + n + 1, 0x3fffffff);
    d[i][i] = 0;
  }
  while (m--) {
    int u, v, b;
    cin >> u >> v >> b;
    d[u][v] = 0;
    d[v][u] = !b;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  cin >> k;
  while (k--) {
    int s, e;
    cin >> s >> e;
    cout << d[s][e] << '\n';
  }
}