// http://boj.kr/a869f456d4e742f28e894b025feb0cf0
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board1[8][8];
int board2[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
vector<pair<int, int>> cand;
bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= m; }

int bfs() {
  bool vis[8][8] = {};
  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board2[i][j] == 2) {
        vis[i][j] = 1;
        Q.push({i, j});
      }
    }
  }
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || board2[nx][ny] != 0 || vis[nx][ny]) continue;
      board2[nx][ny] = 2;
      vis[nx][ny] = 1;
      Q.push({nx, ny});
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (board2[i][j] == 0) cnt++;
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board1[i][j];
      if (board1[i][j] == 0) cand.push_back({i, j});
    }
  }
  vector<bool> brute(cand.size());
  for (int i = 3; i < cand.size(); i++) brute[i] = 1;
  int ans = 0;
  do {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) board2[i][j] = board1[i][j];
    for (int i = 0; i < cand.size(); i++)
      if (brute[i] == 0) board2[cand[i].X][cand[i].Y] = 1;
    ans = max(ans, bfs());
  } while (next_permutation(brute.begin(), brute.end()));
  cout << ans;
}