// http://boj.kr/fc68fd54dab54c83a83430ca5b259dc7
#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int t[101];
int d[101][101];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) {
    fill(d[i] + 1, d[i] + n + 1, 0x3fffffff);
    d[i][i] = 0;
  }
  for (int i = 1; i <= n; i++) cin >> t[i];
  while (r--) {
    int a, b, l;
    cin >> a >> b >> l;
    d[a][b] = l;
    d[b][a] = l;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++)
      if (d[i][j] <= m) sum += t[j];
    ans = max(ans, sum);
  }
  cout << ans;
}