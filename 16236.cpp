// http://boj.kr/eacd674930c64c39bb3ebbb4d93ea80a
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int board[20][20];
int dist[20][20];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
pair<int, int> shark;
int sz = 2;
int cnt = 0;
bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= n; }

tuple<int, int, int> bfs() {
  for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
  queue<pair<int, int>> Q;
  dist[shark.X][shark.Y] = 0;
  Q.push({shark.X, shark.Y});
  tuple<int, int, int> mn = {0x7fffffff, 0x7fffffff, 0x7fffffff};
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || board[nx][ny] > sz || dist[nx][ny] >= 0) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      if (board[nx][ny] != 0 && board[nx][ny] < sz)
        mn = min(mn, {dist[nx][ny], nx, ny});
      Q.push({nx, ny});
    }
  }
  return mn;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 9) {
        shark = {i, j};
        board[i][j] = 0;
      }
    }
  }
  int ans = 0;
  while (true) {
    int dist, x, y;
    tie(dist, x, y) = bfs();
    if (dist == 0x7fffffff) break;
    shark = {x, y};
    if (++cnt == sz) {
      sz++;
      cnt = 0;
    }
    board[x][y] = 0;
    ans += dist;
  }
  cout << ans;
}