// http://boj.kr/3324302228bb443f8a39cfbb7d3105f9
#include <bits/stdc++.h>
using namespace std;

int a[20000];
int b[20000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i] > b[j]) ans++;
      }
    }
    cout << ans << '\n';
  }
}