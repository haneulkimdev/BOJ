// http://boj.kr/cf18903ee5a642e8a09f7fc9441baefc
#include <bits/stdc++.h>
using namespace std;
int board[100][100][100];
int dist[100][100][100];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n, h;
  cin >> m >> n >> h;
  queue<tuple<int, int, int>> Q;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        cin >> board[j][k][i];
        if (board[j][k][i] == 1) Q.push({j, k, i});
        if (board[j][k][i] == 0) dist[j][k][i] = -1;
      }
    }
  }
  while (!Q.empty()) {
    int curX, curY, curZ;
    tie(curX, curY, curZ) = Q.front();
    Q.pop();
    for (int dir = 0; dir < 6; dir++) {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nz = curZ + dz[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
      if (dist[nx][ny][nz] >= 0) continue;
      dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
      Q.push({nx, ny, nz});
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < h; k++) {
        if (dist[i][j][k] == -1) {
          cout << -1;
          return 0;
        }
        ans = max(ans, dist[i][j][k]);
      }
    }
  }
  cout << ans;
}