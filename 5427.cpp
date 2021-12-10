// http://boj.kr/17277ce4dcbc40c1b1da757010457ecc
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1000];
int dist1[1000][1000];
int dist2[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
      fill(dist1[i], dist1[i] + w, -1);
      fill(dist2[i], dist2[i] + w, -1);
    }
    for (int i = 0; i < h; i++) cin >> board[i];
    queue<pair<int, int>> Q1;
    queue<pair<int, int>> Q2;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (board[i][j] == '*') {
          Q1.push({i, j});
          dist1[i][j] = 0;
        }
        if (board[i][j] == '@') {
          Q2.push({i, j});
          dist2[i][j] = 0;
        }
      }
    }
    while (!Q1.empty()) {
      auto cur = Q1.front();
      Q1.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
        dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
        Q1.push({nx, ny});
      }
    }
    bool is_possible = false;
    int ans = 0;
    while (!Q2.empty() && !is_possible) {
      auto cur = Q2.front();
      Q2.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
          is_possible = true;
          ans = dist2[cur.X][cur.Y] + 1;
          break;
        }
        if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
        if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
          continue;
        dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
        Q2.push({nx, ny});
      }
    }
    if (is_possible)
      cout << ans << '\n';
    else
      cout << "IMPOSSIBLE\n";
  }
}