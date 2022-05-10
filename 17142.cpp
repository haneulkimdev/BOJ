// http://boj.kr/5a12cbc7a45647e48ee45a98bc2a5123
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[50][50];
int dist[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> cand;
int cnt1 = 0;
bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= n; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0) cnt1++;
      if (board[i][j] == 2) cand.push_back({i, j});
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
    int cnt2 = 0;
    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (OOB(nx, ny) || board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
        Q.push({nx, ny});
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        if (board[nx][ny] != 2) {
          time = max(time, dist[nx][ny]);
          cnt2++;
        }
      }
    }
    if (cnt1 == cnt2) ans = min(ans, time);
  } while (next_permutation(brute.begin(), brute.end()));
  if (ans == 0x7fffffff) ans = -1;
  cout << ans;
}