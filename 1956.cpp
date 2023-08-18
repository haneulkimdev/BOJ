// http://boj.kr/734dae00fac348c9a8ef5075feb21dfd
#include <bits/stdc++.h>
using namespace std;

int d[401][401];
int v, e;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> v >> e;
  for (int i = 1; i <= v; i++) fill(d[i] + 1, d[i] + v + 1, 0x3fffffff);
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    d[a][b] = c;
  }
  for (int k = 1; k <= v; k++)
    for (int i = 1; i <= v; i++)
      for (int j = 1; j <= v; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  int mn = 0x3fffffff;
  for (int i = 1; i <= v; i++) mn = min(mn, d[i][i]);
  if (mn == 0x3fffffff)
    cout << -1;
  else
    cout << mn;
}