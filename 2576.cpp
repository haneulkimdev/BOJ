// http://boj.kr/f5f14dbb0ba143ffb2cd0efa81be2606
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int sum = 0;
  int mn = 0x7fffffff;
  for (int i = 0; i < 7; i++) {
    int t;
    cin >> t;
    if (t % 2 == 1) {
      sum += t;
      mn = min(mn, t);
    }
  }
  if (sum == 0)
    cout << -1;
  else
    cout << sum << '\n' << mn;
}