// http://boj.kr/9e685655837844f8873c4f1b6620f950
#include <bits/stdc++.h>
using namespace std;

int d[20][20];
bool chk[20][20];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> d[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        if (d[i][k] + d[k][j] < d[i][j]) {
          cout << -1;
          return 0;
        }
        if (d[i][k] + d[k][j] == d[i][j]) chk[i][j] = true;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (!chk[i][j]) ans += d[i][j];
  cout << ans;
}