// http://boj.kr/32831483506544baa6ec6e500c021cc5
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, k;
int a[11][11];
int board[11][11];
vector<int> tree[11][11];
bool OOB(int a, int b) { return a < 1 || a > n || b < 1 || b > n; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    tree[x][y].push_back(z);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) board[i][j] = 5;
  while (k--) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int idx;
        for (idx = tree[i][j].size() - 1; idx >= 0; idx--) {
          if (board[i][j] < tree[i][j][idx]) break;
          board[i][j] -= tree[i][j][idx];
          tree[i][j][idx]++;
        }
        for (int k = 0; k <= idx; k++) board[i][j] += tree[i][j][k] / 2;
        tree[i][j].erase(tree[i][j].begin(), tree[i][j].begin() + idx + 1);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (auto t : tree[i][j]) {
          if (t % 5 != 0) continue;
          for (int dir = 0; dir < 8; dir++) {
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if (OOB(nx, ny)) continue;
            tree[nx][ny].push_back(1);
          }
        }
        board[i][j] += a[i][j];
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) ans += tree[i][j].size();
  cout << ans;
}