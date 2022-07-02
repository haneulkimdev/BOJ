//http://boj.kr/013cf5cb436d4938878336cc311c72d9
#include <bits/stdc++.h>
using namespace std;

int d[1001][3];
int r[1001], g[1001], b[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> r[i] >> g[i] >> b[i];
  d[1][0] = r[1];
  d[1][1] = g[1];
  d[1][2] = b[1];
  for (int i = 2; i <= n; i++) {
    d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
    d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
    d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];
  }
  cout << *min_element(d[n], d[n] + 3);
}