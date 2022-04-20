// http://boj.kr/6253d927dbc645ecbef178da2adf1f84
#include <bits/stdc++.h>
using namespace std;

int board[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int x, y, d;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  cin >> x >> y >> d;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> board[i][j];
  int ans = 0;
  while (true) {
    if (board[x][y] == 0) {
      board[x][y] = 2;
      ans++;
    }
    bool is_cleaned = false;
    for (int cnt = 0; cnt < 4; cnt++) {
      d = (d + 3) % 4;
      if (board[x + dx[d]][y + dy[d]] != 0) continue;
      x += dx[d];
      y += dy[d];
      is_cleaned = true;
      break;
    }
    if (is_cleaned) continue;
    if (board[x - dx[d]][y - dy[d]] == 1) break;
    x -= dx[d];
    y -= dy[d];
  }
  cout << ans;
}