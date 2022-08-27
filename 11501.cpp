// http://boj.kr/4c489810ae4c421ea7c2aa9e0588c5ab
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    int mx = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      mx = max(mx, a[i]);
      ans += mx - a[i];
    }
    cout << ans << '\n';
  }
}