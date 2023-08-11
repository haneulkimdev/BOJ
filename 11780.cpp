// http://boj.kr/df91f168f5db4d5fba4fd8fe65fc835c
#include <bits/stdc++.h>
using namespace std;

int d[101][101];
int nxt[101][101];
int n, m;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    fill(d[i] + 1, d[i] + n + 1, 0x3fffffff);
    d[i][i] = 0;
  }
  cin >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b], c);
    nxt[a][b] = b;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d[i][j] == 0x3fffffff)
        cout << "0 ";
      else
        cout << d[i][j] << ' ';
    }
    cout << '\n';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d[i][j] == 0 || d[i][j] == 0x3fffffff) {
        cout << "0\n";
        continue;
      }
      vector<int> path;
      int st = i;
      while (st != j) {
        path.push_back(st);
        st = nxt[st][j];
      }
      path.push_back(j);
      cout << path.size() << ' ';
      for (auto x : path) cout << x << ' ';
      cout << '\n';
    }
  }
}