// http://boj.kr/b1ab07c40a08466d86cef6625177bc86
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[50][50];
int dist[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
vector<pair<int, int>> cand;
bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= n; }

bool chk() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (board[i][j] == 0 && dist[i][j] == -1) return false;
  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) {
        cand.push_back({i, j});
        board[i][j] = 0;
      }
    }
  }
  vector<bool> brute(cand.size());
  for (int i = m; i < cand.size(); i++) brute[i] = 1;
  int ans = 0x7fffffff;
  do {
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
    queue<pair<int, int>> Q;
    for (int i = 0; i < cand.size(); i++) {
      if (brute[i] == 0) {
        Q.push({cand[i].X, cand[i].Y});
        dist[cand[i].X][cand[i].Y] = 0;
      }
    }
    int time = 0;
    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (OOB(nx, ny) || board[nx][ny] != 0 || dist[nx][ny] >= 0) continue;
        Q.push({nx, ny});
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        time = max(time, dist[nx][ny]);
      }
    }
    if (chk()) ans = min(ans, time);
  } while (next_permutation(brute.begin(), brute.end()));
  if (ans == 0x7fffffff) ans = -1;
  cout << ans;
}