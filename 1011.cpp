// http://boj.kr/fd3ece3edc5e4c318e8db0d8282daabf
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    for (long long i = 1; i <= y - x; i++) {
      if (i * i >= y - x) {
        cout << 2 * i - 1 << '\n';
        break;
      } else if (i * (i + 1) >= y - x) {
        cout << 2 * i << '\n';
        break;
      }
    }
  }
}