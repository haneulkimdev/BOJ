// http://boj.kr/b80f504f67b94018aa3af43be430c904
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans1 = 1000000000;
  int ans2 = 1000000000;
  for (int i = 0; i < n; i++) {
    int idx = lower_bound(a, a + n, -a[i]) - a;
    for (int j = idx - 1; j <= idx + 1; j++) {
      if (j < 0 || j >= n) continue;
      if (i == j) continue;
      if (abs(a[i] + a[j]) < abs(ans1 + ans2)) {
        ans1 = a[i];
        ans2 = a[j];
      }
    }
  }
  if (ans1 > ans2) swap(ans1, ans2);
  cout << ans1 << ' ' << ans2;
}