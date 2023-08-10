// http://boj.kr/61c493931710429f85c016384065dfdd
#include <bits/stdc++.h>
using namespace std;

int d[101][101];
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
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d[i][j] == 0x3fffffff)
        cout << "0 ";
      else
        cout << d[i][j] << ' ';
    }
    cout << '\n';
  }
}