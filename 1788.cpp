// http://boj.kr/64ae37763e98439e9e0c76bc94a1278f
#include <bits/stdc++.h>
using namespace std;

int d[1000001];
int mod = 1000000000;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  d[1] = 1;
  for (int i = 2; i <= abs(n); i++) d[i] = (d[i - 1] + d[i - 2]) % mod;
  if (n > 0)
    cout << 1 << '\n';
  else if (n == 0)
    cout << 0 << '\n';
  else
    cout << pow(-1, n + 1) << '\n';
  cout << d[abs(n)];
}