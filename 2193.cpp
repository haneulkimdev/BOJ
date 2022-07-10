// http://boj.kr/36150745dc1648c4bd4a249108f8c10c
#include <bits/stdc++.h>
using namespace std;

long long d[91][2];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  d[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    d[i][0] = d[i - 1][0] + d[i - 1][1];
    d[i][1] = d[i - 1][0];
  }
  cout << d[n][0] + d[n][1];
}