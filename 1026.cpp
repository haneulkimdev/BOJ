// http://boj.kr/3286590fd2d349bbacaa2226aa369328
#include <bits/stdc++.h>
using namespace std;

int a[50], b[50];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  int ans = 0;
  for (int i = 0; i < n; i++) ans += a[i] * b[n - 1 - i];
  cout << ans;
}