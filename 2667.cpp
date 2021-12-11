// http://boj.kr/36e9a5ac93aa4d6fbce91c06b985210e
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[25];
bool vis[25][25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> board[i];
  int num = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == '0' || vis[i][j]) continue;
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
          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (vis[nx][ny] || board[nx][ny] == '0') continue;
          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }
      v.push_back(area);
    }
  }
  sort(v.begin(), v.end());
  cout << num << '\n';
  for (int i : v) cout << i << '\n';
}