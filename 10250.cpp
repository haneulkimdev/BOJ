// http://boj.kr/c697b2adb2eb4c93876674084528051a
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w, n;
    cin >> h >> w >> n;
    cout << ((n - 1) % h + 1) * 100 + ((n - 1) / h + 1) << '\n';
  }
}