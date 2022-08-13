// http://boj.kr/e2b62ddec93c464d883649029679456f
#include <bits/stdc++.h>
using namespace std;

int p[1000];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  sort(p, p + n);
  int ans = 0;
  for (int i = 0; i < n; i++) ans += p[i] * (n - i);
  cout << ans;
}