// http://boj.kr/d94547af292e4c538b0b85787b7f44d9
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[200][200];
int dist[200][200][31];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int kx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ky[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int w, h;
bool OOB(int a, int b) { return a < 0 || a >= h || b < 0 || b >= w; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  cin >> w >> h;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) fill(dist[i][j], dist[i][j] + 31, -1);
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) cin >> board[i][j];
  queue<tuple<int, int, int>> Q;
  Q.push({0, 0, 0});
  dist[0][0][0] = 0;
  while (!Q.empty()) {
    int curX, curY, cnt;
    tie(curX, curY, cnt) = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      if (OOB(nx, ny) || dist[nx][ny][cnt] >= 0 || board[nx][ny] == 1) continue;
      Q.push({nx, ny, cnt});
      dist[nx][ny][cnt] = dist[curX][curY][cnt] + 1;
    }
    if (cnt < k) {
      for (int dir = 0; dir < 8; dir++) {
        int nx = curX + kx[dir];
        int ny = curY + ky[dir];
        if (OOB(nx, ny) || dist[nx][ny][cnt + 1] >= 0 || board[nx][ny] == 1)
          continue;
        Q.push({nx, ny, cnt + 1});
        dist[nx][ny][cnt + 1] = dist[curX][curY][cnt] + 1;
      }
    }
  }
  int ans = 0x7fffffff;
  for (int i = 0; i <= k; i++)
    if (dist[h - 1][w - 1][i] >= 0) ans = min(ans, dist[h - 1][w - 1][i]);
  if (ans == 0x7fffffff) ans = -1;
  cout << ans;
}