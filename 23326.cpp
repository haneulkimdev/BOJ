// http://boj.kr/bbbc2aaba1784148ae1885de7d4cec06
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    if (t == 1) s.insert(i);
  }
  int cur = 1;
  while (q--) {
    char com;
    cin >> com;
    if (com == '1') {
      int i;
      cin >> i;
      if (s.find(i) != s.end())
        s.erase(i);
      else
        s.insert(i);
    } else if (com == '2') {
      int x;
      cin >> x;
      cur = (cur + x - 1) % n + 1;
    } else if (com == '3') {
      if (s.empty()) {
        cout << -1 << '\n';
        continue;
      }
      auto it = s.lower_bound(cur);
      if (it != s.end())
        cout << *it - cur << '\n';
      else
        cout << n - cur + *s.begin() << '\n';
    }
  }
}