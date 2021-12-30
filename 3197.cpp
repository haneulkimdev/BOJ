// http://boj.kr/2099a1f2747f4e3bb4a5558bc4bbbe41
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1500];
bool vis[1500][1500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int lx, ly;
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;
int r, c;
bool OOB(int a, int b) { return a < 0 || a >= r || b < 0 || b >= c; }

bool status() {
  vis[lx][ly] = 1;
  Q2.push({lx, ly});
  queue<pair<int, int>> tmp;
  while (!Q2.empty()) {
    auto cur = Q2.front();
    Q2.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      if (board[nx][ny] == 'X') {
        tmp.push({nx, ny});
        continue;
      }
      if (board[nx][ny] == 'L') return true;
      Q2.push({nx, ny});
    }
  }
  Q2 = tmp;
  return false;
}

void run() {
  int sz = Q1.size();
  while (sz--) {
    auto cur = Q1.front();
    Q1.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || board[nx][ny] != 'X') continue;
      board[nx][ny] = '.';
      Q1.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> board[i];
    for (int j = 0; j < c; j++) {
      if (board[i][j] != 'X') Q1.push({i, j});
      if (board[i][j] == 'L') {
        lx = i;
        ly = j;
      }
    }
  }
  int ans = 0;
  while (true) {
    if (status()) break;
    run();
    ans++;
  }
  cout << ans;
}