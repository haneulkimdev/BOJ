// http://boj.kr/38c3c5a3522c4f518e48c1d04c7f6d07
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[100][100];
bool vis[100][100];
int dist[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

void island() {
  int idx = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0 || vis[i][j]) continue;
      queue<pair<int, int>> Q;
      vis[i][j] = 1;
      Q.push({i, j});
      while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        board[cur.X][cur.Y] = idx;
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (vis[nx][ny] || board[nx][ny] != 1) continue;
          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }
      idx++;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> board[i][j];
  island();
  for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0) continue;
      dist[i][j] = 0;
      Q.push({i, j});
    }
  }
  int ans = 0x7fffffff;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (board[nx][ny] == board[cur.X][cur.Y]) continue;
      if (board[nx][ny] != 0) {
        ans = min(ans, dist[nx][ny] + dist[cur.X][cur.Y]);
      } else {
        board[nx][ny] = board[cur.X][cur.Y];
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        Q.push({nx, ny});
      }
    }
  }
  cout << ans;
}