// http://boj.kr/7fdb17d743504d96abc53636b117db1a
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool OOB(int a, int b) { return a < 0 || a >= 12 || b < 0 || b >= 6; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 12; i++) cin >> board[i];
  bool is_chain;
  int ans = 0;
  do {
    is_chain = false;
    bool vis[12][6] = {};
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 6; j++) {
        if (board[i][j] == '.' || vis[i][j]) continue;
        char color = board[i][j];
        queue<pair<int, int>> Q;
        vector<pair<int, int>> tmp;
        Q.push({i, j});
        tmp.push_back({i, j});
        vis[i][j] = 1;
        while (!Q.empty()) {
          auto cur = Q.front();
          Q.pop();
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] != color) continue;
            Q.push({nx, ny});
            tmp.push_back({nx, ny});
            vis[nx][ny] = 1;
          }
        }
        if (tmp.size() >= 4) {
          is_chain = true;
          for (auto cur : tmp) board[cur.X][cur.Y] = '.';
        }
      }
    }
    for (int c = 0; c < 6; c++) {
      char fallen[12];
      fill(fallen, fallen + 12, '.');
      int idx = 11;
      for (int r = 11; r >= 0; r--) {
        if (board[r][c] == '.') continue;
        if (fallen[idx] == '.')
          fallen[idx] = board[r][c];
        else
          fallen[--idx] = board[r][c];
      }
      for (int r = 0; r < 12; r++) board[r][c] = fallen[r];
    }
    if (is_chain) ans++;
  } while (is_chain);
  cout << ans;
}