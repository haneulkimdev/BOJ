// http://boj.kr/d28d7c704f494fc3b6b9fdc3b4485ca7
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[100];
bool vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

void bfs(int i, int j) {
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
      if (vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
}

int area() {
  int num = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j]) continue;
      num++;
      bfs(i, j);
    }
  }
  return num;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> board[i];
  int human = area();
  for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'G') board[i][j] = 'R';
    }
  }
  int cow = area();
  cout << human << ' ' << cow;
}