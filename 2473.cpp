// http://boj.kr/5a6a4fb3dcdd4fc781ad993b521f53c3
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
ll a[5000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  ll ans[3];
  fill(ans, ans + 3, 1000000000);
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int idx = lower_bound(a + j + 1, a + n, -(a[i] + a[j])) - a;
      for (int k = idx - 1; k <= idx + 1; k++) {
        if (k < 0 || k >= n) continue;
        if (k == i || k == j) continue;
        if (abs(a[i] + a[j] + a[k]) < abs(ans[0] + ans[1] + ans[2])) {
          ans[0] = a[i];
          ans[1] = a[j];
          ans[2] = a[k];
        }
      }
    }
  }
  sort(ans, ans + 3);
  for (int i = 0; i < 3; i++) cout << ans[i] << ' ';
}