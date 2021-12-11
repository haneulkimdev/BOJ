// http://boj.kr/abed0046cb3c46c6b031307d24df1e42
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[100][100];
bool vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

void bfs(int i, int j, int height) {
  queue<pair<int, int>> Q;
  vis[i][j] = 1;
  Q.push({i, j});
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (vis[nx][ny] || board[nx][ny] <= height) continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int mx_height = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      mx_height = max(mx_height, board[i][j]);
    }
  }
  int ans = 0;
  for (int height = 0; height <= mx_height; height++) {
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
    int num = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] <= height || vis[i][j]) continue;
        num++;
        bfs(i, j, height);
      }
    }
    ans = max(num, ans);
  }
  cout << ans;
}