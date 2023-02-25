// http://boj.kr/da18568a3cd3420693879c86904616c4
#include <bits/stdc++.h>
using namespace std;

int d[1001];
int mod = 10007;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  d[1] = 1;
  d[2] = 3;
  for (int i = 3; i <= n; i++) d[i] = (d[i - 1] + d[i - 2] * 2) % mod;
  cout << d[n];
}