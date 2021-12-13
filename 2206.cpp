// http://boj.kr/9533333e093b4670b08cae828472982d
#include <bits/stdc++.h>
using namespace std;
string board[1000];
int dist[1000][1000][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> board[i];
  queue<tuple<int, int, int>> Q;
  Q.push({0, 0, 0});
  dist[0][0][0] = 1;
  while (!Q.empty()) {
    int curX, curY, broken;
    tie(curX, curY, broken) = Q.front();
    Q.pop();
    if (curX == n - 1 && curY == m - 1) {
      cout << dist[curX][curY][broken];
      return 0;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (dist[nx][ny][broken] > 0) continue;
      if (board[nx][ny] == '0') {
        Q.push({nx, ny, broken});
        dist[nx][ny][broken] = dist[curX][curY][broken] + 1;
      }
      if (!broken && board[nx][ny] == '1') {
        Q.push({nx, ny, 1});
        dist[nx][ny][1] = dist[curX][curY][broken] + 1;
      }
    }
  }
  cout << -1;
}