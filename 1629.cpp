// http://boj.kr/577aa694574f44e9a996aae3d002ca30
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll POW(int a, int b, int m) {
  if (b == 1) return a % m;
  ll val = POW(a, b / 2, m);
  val = val * val % m;
  if (b % 2 == 0) return val;
  return val * a % m;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a, b, c;
  cin >> a >> b >> c;
  cout << POW(a, b, c);
}