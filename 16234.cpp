// http://boj.kr/7117724ce0c943cbaa22e2466a6a8a17
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, l, r;
int board[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= n; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> board[i][j];
  bool is_occur;
  int ans = 0;
  do {
    is_occur = false;
    bool vis[50][50] = {};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (vis[i][j]) continue;
        int sum = board[i][j];
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
            if (OOB(nx, ny) || vis[nx][ny]) continue;
            if (abs(board[cur.X][cur.Y] - board[nx][ny]) < l ||
                abs(board[cur.X][cur.Y] - board[nx][ny]) > r)
              continue;
            is_occur = true;
            sum += board[nx][ny];
            Q.push({nx, ny});
            tmp.push_back({nx, ny});
            vis[nx][ny] = 1;
          }
        }
        for (auto cur : tmp) board[cur.X][cur.Y] = sum / tmp.size();
      }
    }
    if (is_occur) ans++;
  } while (is_occur);
  cout << ans;
}