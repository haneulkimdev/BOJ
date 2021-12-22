// http://boj.kr/6103f92081fb4c5a925a07a19bf8449e
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q[10];
int cnt[10];
int n, m, p;
int s[10];
bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= m; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> p;
  for (int i = 1; i <= p; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    cin >> board[i];
    for (int j = 0; j < m; j++) {
      if (!isdigit(board[i][j])) continue;
      q[board[i][j] - '0'].push({i, j});
      cnt[board[i][j] - '0']++;
    }
  }
  while (true) {
    bool state = true;
    for (int i = 1; i <= p; i++) {
      int dist = s[i];
      while (!q[i].empty() && dist--) {
        state = false;
        int sz = q[i].size();
        while (sz--) {
          auto cur = q[i].front();
          q[i].pop();
          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (OOB(nx, ny) || board[nx][ny] != '.') continue;
            board[nx][ny] = i + '0';
            q[i].push({nx, ny});
            cnt[i]++;
          }
        }
      }
    }
    if (state) break;
  }
  for (int i = 1; i <= p; i++) cout << cnt[i] << ' ';
}