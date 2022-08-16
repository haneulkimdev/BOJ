// http://boj.kr/deb1151fb4e84fd0a60b32cb7798eb47
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
pair<int, int> flower[100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    flower[i].X = a * 100 + b;
    flower[i].Y = c * 100 + d;
  }
  int ans = 0;
  int t = 301;
  while (t <= 1130) {
    int nxt_t = t;
    for (int i = 0; i < n; i++)
      if (flower[i].X <= t && flower[i].Y > nxt_t) nxt_t = flower[i].Y;
    if (nxt_t == t) {
      cout << 0;
      return 0;
    }
    ans++;
    t = nxt_t;
  }
  cout << ans;
}