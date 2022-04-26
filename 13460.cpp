// http://boj.kr/a9148ce2d41a4bd0b4caad7502363e33
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
pair<int, int> red, blue;
string board[10];
int dist[10][10][10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs() {
  queue<tuple<int, int, int, int>> Q;
  Q.push({red.X, red.Y, blue.X, blue.Y});
  dist[red.X][red.Y][blue.X][blue.Y] = 0;
  while (!Q.empty()) {
    int rx, ry, bx, by;
    tie(rx, ry, bx, by) = Q.front();
    Q.pop();
    if (dist[rx][ry][bx][by] >= 10) return -1;
    for (int dir = 0; dir < 4; dir++) {
      int nrx = rx;
      int nry = ry;
      int nbx = bx;
      int nby = by;
      while (board[nbx + dx[dir]][nby + dy[dir]] == '.') {
        nbx += dx[dir];
        nby += dy[dir];
      }
      if (board[nbx + dx[dir]][nby + dy[dir]] == 'O') continue;
      while (board[nrx + dx[dir]][nry + dy[dir]] == '.') {
        nrx += dx[dir];
        nry += dy[dir];
      }
      if (board[nrx + dx[dir]][nry + dy[dir]] == 'O')
        return dist[rx][ry][bx][by] + 1;
      if (nrx == nbx && nry == nby) {
        if (dir == 0)
          rx < bx ? nrx-- : nbx--;
        else if (dir == 1)
          ry < by ? nry-- : nby--;
        else if (dir == 2)
          rx > bx ? nrx++ : nbx++;
        else if (dir == 3)
          ry > by ? nry++ : nby++;
      }
      if (dist[nrx][nry][nbx][nby] != -1) continue;
      Q.push({nrx, nry, nbx, nby});
      dist[nrx][nry][nbx][nby] = dist[rx][ry][bx][by] + 1;
    }
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> board[i];
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'R') {
        red = {i, j};
        board[i][j] = '.';
      }
      if (board[i][j] == 'B') {
        blue = {i, j};
        board[i][j] = '.';
      }
    }
  }
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k < 10; k++) fill(dist[i][j][k], dist[i][j][k] + 10, -1);
  cout << bfs();
}