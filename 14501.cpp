// http://boj.kr/550677feb95547fb927df14da43476ff
#include <bits/stdc++.h>
using namespace std;

int n;
int t[16], p[16], d[16];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> p[i];
    d[i] = max(d[i], d[i - 1]);
    if (i + t[i] - 1 <= n)
      d[i + t[i] - 1] = max(d[i + t[i] - 1], d[i - 1] + p[i]);
  }
  cout << d[n];
}