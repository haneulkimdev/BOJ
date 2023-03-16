// http://boj.kr/9087776dc1064792a4dfb67c17a05700
#include <bits/stdc++.h>
using namespace std;

int n, m, tot, cnt;
int a[10000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  tot = a[0];
  int en = 0;
  for (int st = 0; st < n; st++) {
    while (en < n && tot < m) {
      en++;
      if (en != n) tot += a[en];
    }
    if (en == n) break;
    cnt += tot == m;
    tot -= a[st];
  }
  cout << cnt;
}