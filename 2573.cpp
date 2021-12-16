// http://boj.kr/2fced74371e142a08823b49e7ee83990
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[300][300];
bool vis[300][300];
int tmp[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= m; }

int status() {
  for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
  queue<pair<int, int>> Q;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 0) continue;
      cnt++;
      if (Q.empty()) {
        vis[i][j] = 1;
        Q.push({i, j});
      }
    }
  }
  if (Q.empty()) return -1;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    cnt--;
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 0) continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
  return cnt != 0;
}

void run() {
  for (int i = 0; i < n; i++) fill(tmp[i], tmp[i] + m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 0) continue;
      int cnt = 0;
      for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (OOB(nx, ny) || board[nx][ny] != 0) continue;
        cnt++;
      }
      tmp[i][j] = max(0, board[i][j] - cnt);
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) board[i][j] = tmp[i][j];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> board[i][j];
  int ans = 0;
  while (true) {
    int check = status();
    if (check == -1) {
      ans = 0;
      break;
    }
    if (check == 1) break;
    run();
    ans++;
  }
  cout << ans;
}