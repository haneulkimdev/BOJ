// http://boj.kr/dcdab82c9eea4699bbf4d8fbeab2d6e8
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, h;
bool is_used[31][11];
vector<pair<int, int>> cand;
int candsz;

bool chk() {
  for (int j = 1; j <= n; j++) {
    int cur = j;
    for (int i = 1; i <= h; i++) {
      if (is_used[i][cur - 1])
        cur--;
      else if (is_used[i][cur])
        cur++;
    }
    if (cur != j) return false;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> h;
  while (m--) {
    int a, b;
    cin >> a >> b;
    is_used[a][b] = 1;
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j < n; j++) {
      if (is_used[i][j - 1] || is_used[i][j] || is_used[i][j + 1]) continue;
      cand.push_back({i, j});
    }
  }
  if (chk()) {
    cout << 0;
    return 0;
  }
  candsz = cand.size();
  int ans = 0x7fffffff;
  for (int i = 0; i < candsz; i++) {
    is_used[cand[i].X][cand[i].Y] = 1;
    if (chk()) ans = min(ans, 1);
    for (int j = i + 1; j < candsz; j++) {
      is_used[cand[j].X][cand[j].Y] = 1;
      if (chk()) ans = min(ans, 2);
      for (int k = j + 1; k < candsz; k++) {
        is_used[cand[k].X][cand[k].Y] = 1;
        if (chk()) ans = min(ans, 3);
        is_used[cand[k].X][cand[k].Y] = 0;
      }
      is_used[cand[j].X][cand[j].Y] = 0;
    }
    is_used[cand[i].X][cand[i].Y] = 0;
  }
  if (ans == 0x7fffffff) ans = -1;
  cout << ans;
}