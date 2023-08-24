// http://boj.kr/61a47ba9bca74add9a9d1fdbec793e9d
#include <bits/stdc++.h>
using namespace std;

int d[201][201];
int nxt[201][201];
int n, m;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fill(d[i] + 1, d[i] + n + 1, 0x3fffffff);
    d[i][i] = 0;
  }
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    d[a][b] = c;
    d[b][a] = c;
    nxt[a][b] = b;
    nxt[b][a] = a;
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
    for (int j = 1; j <= n; j++)
      if (i == j)
        cout << "- ";
      else
        cout << nxt[i][j] << ' ';
    cout << '\n';
  }
}