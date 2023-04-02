// http://boj.kr/d938c172012a4e80abccd338dd4d974d
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
int p, q;
unordered_map<ll, ll> m;

ll solve(ll k) {
  if (k == 0) return 1;
  if (m.find(k) != m.end()) return m[k];
  return m[k] = solve(k / p) + solve(k / q);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p >> q;
  cout << solve(n);
}