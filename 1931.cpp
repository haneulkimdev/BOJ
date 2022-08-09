// http://boj.kr/c6bfd54560fb434792af01e163d160e2
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
pair<int, int> s[100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i].Y >> s[i].X;
  sort(s, s + n);
  int ans = 0;
  int t = 0;
  for (int i = 0; i < n; i++) {
    if (t > s[i].Y) continue;
    ans++;
    t = s[i].X;
  }
  cout << ans;
}