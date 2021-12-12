// http://boj.kr/7fa1fd63249d48c580c9f02281441923
#include <bits/stdc++.h>
using namespace std;

string board[30][30];
int dist[30][30][30];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    int l, r, c;
    cin >> l >> r >> c;
    if (l == 0 && r == 0 && c == 0) break;
    for (int i = 0; i < l; i++)
      for (int j = 0; j < r; j++) fill(dist[i][j], dist[i][j] + c, -1);
    queue<tuple<int, int, int>> Q;
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        cin >> board[i][j];
        for (int k = 0; k < c; k++) {
          if (board[i][j][k] == 'S') {
            dist[i][j][k] = 0;
            Q.push({i, j, k});
          }
        }
      }
    }
    bool is_possible = false;
    while (!Q.empty() && !is_possible) {
      int curX, curY, curZ;
      tie(curZ, curX, curY) = Q.front();
      Q.pop();
      for (int dir = 0; dir < 6; dir++) {
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        int nz = curZ + dz[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l)
          continue;
        if (dist[nz][nx][ny] >= 0 || board[nz][nx][ny] == '#') continue;
        dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
        if (board[nz][nx][ny] == 'E') {
          is_possible = true;
          cout << "Escaped in " << dist[nz][nx][ny] << " minute(s).\n";
          break;
        }
        Q.push({nz, nx, ny});
      }
    }
    if (!is_possible) cout << "Trapped!\n";
  }
}