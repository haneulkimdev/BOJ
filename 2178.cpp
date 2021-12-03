// http://boj.kr/ff3f871352184847bdcd90814d7bd2cb
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[100];
int dist[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> board[i];
  queue<pair<int, int>> Q;
  dist[0][0] = 1;
  Q.push({0, 0});
  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (dist[nx][ny] > 0 || board[nx][ny] != '1') continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }
  cout << dist[n - 1][m - 1];
}