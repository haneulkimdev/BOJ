// http://boj.kr/e14d2d62bbb44ad0ae932f115866538c
#include <bits/stdc++.h>
using namespace std;

int n;
int a[2000];

bool solve(int x) {
  for (int i = 0; i < n; i++) {
    if (i == x) continue;
    int idx = lower_bound(a, a + n, a[x] - a[i]) - a;
    while (idx < upper_bound(a, a + n, a[x] - a[i]) - a) {
      if (idx != x && idx != i) return true;
      idx++;
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) ans += solve(i);
  cout << ans;
}