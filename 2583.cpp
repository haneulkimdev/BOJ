// http://boj.kr/9c6a1391b5d64e69860ed569a3732dfe
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[100][100];
bool vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n, k;
  cin >> m >> n >> k;
  while (k--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i < x2; i++)
      for (int j = y1; j < y2; j++) board[i][j] = 1;
  }
  int num = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 1 || vis[i][j]) continue;
      num++;
      queue<pair<int, int>> Q;
      vis[i][j] = 1;
      Q.push({i, j});
      int area = 0;
      while (!Q.empty()) {
        area++;
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (vis[nx][ny] || board[nx][ny] == 1) continue;
          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }
      v.push_back(area);
    }
  }
  sort(v.begin(), v.end());
  cout << num << '\n';
  for (int i : v) cout << i << ' ';
}