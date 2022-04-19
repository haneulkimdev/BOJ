// http://boj.kr/8576acc7c2ba4fa89e5badfd84b2bf6e
#include <bits/stdc++.h>
using namespace std;

int board[4][5][5][5];
int maze[5][5][5];

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
bool OOB(int a, int b, int c) {
  return a < 0 || a >= 5 || b < 0 || b >= 5 || c < 0 || c >= 5;
}

int func() {
  int dist[5][5][5] = {};
  if (maze[0][0][0] == 0 || maze[4][4][4] == 0) return 0x7fffffff;

  queue<tuple<int, int, int>> Q;
  Q.push({0, 0, 0});
  dist[0][0][0] = 1;
  while (!Q.empty()) {
    int curX, curY, curZ;
    tie(curX, curY, curZ) = Q.front();
    Q.pop();
    for (int dir = 0; dir < 6; dir++) {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nz = curZ + dz[dir];
      if (OOB(nx, ny, nz) || maze[nx][ny][nz] == 0 || dist[nx][ny][nz] > 0)
        continue;
      if (nx == 4 && ny == 4 && nz == 4) return dist[curX][curY][curZ];
      Q.push({nx, ny, nz});
      dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
    }
  }
  return 0x7fffffff;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++)
      for (int k = 0; k < 5; k++) cin >> board[0][i][j][k];

    for (int j = 0; j < 5; j++)
      for (int k = 0; k < 5; k++) board[1][i][j][k] = board[0][i][4 - k][j];

    for (int j = 0; j < 5; j++)
      for (int k = 0; k < 5; k++) board[2][i][j][k] = board[1][i][4 - k][j];

    for (int j = 0; j < 5; j++)
      for (int k = 0; k < 5; k++) board[3][i][j][k] = board[2][i][4 - k][j];
  }

  int order[5] = {0, 1, 2, 3, 4};
  int ans = 0x7fffffff;
  do {
    for (int tmp = 0; tmp < 1024; tmp++) {
      int brute = tmp;
      for (int i = 0; i < 5; i++) {
        int dir = brute % 4;
        brute /= 4;
        for (int j = 0; j < 5; j++)
          for (int k = 0; k < 5; k++)
            maze[i][j][k] = board[dir][order[i]][j][k];
      }
      ans = min(ans, func());
    }
  } while (next_permutation(order, order + 5));

  if (ans == 0x7fffffff) ans = -1;
  cout << ans;
}