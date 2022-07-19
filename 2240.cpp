// http://boj.kr/2c3c5109ab884e1db9517a4e62bef76c
#include <bits/stdc++.h>
using namespace std;

int t, w;
int a[1001], d[1001][31];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t >> w;
  for (int i = 1; i <= t; i++) {
    cin >> a[i];
    d[i][0] = d[i - 1][0] + (a[i] == 1 ? 1 : 0);
    for (int j = 1; j <= w; j++)
      d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + (j % 2 + 1 == a[i]);
  }
  cout << *max_element(d[t], d[t] + w + 1);
}