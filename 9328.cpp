// http://boj.kr/d6621192f92a477b9d256d47e150704f
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[102][102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> door[26];
bool key[26];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h + 2; i++) {
      fill(board[i], board[i] + w + 2, 0);
      fill(vis[i], vis[i] + w + 2, 0);
    }
    for (int i = 0; i < 26; i++) door[i].clear();
    fill(key, key + 26, 0);
    for (int i = 1; i <= h; i++)
      for (int j = 1; j <= w; j++) cin >> board[i][j];
    string keys;
    cin >> keys;
    for (auto c : keys)
      if (islower(c)) key[c - 'a'] = 1;
    queue<pair<int, int>> Q;
    vis[0][0] = 1;
    Q.push({0, 0});
    int ans = 0;
    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || nx >= h + 2 || ny < 0 || ny >= w + 2) continue;
        if (vis[nx][ny] || board[nx][ny] == '*') continue;
        vis[nx][ny] = 1;
        if (board[nx][ny] == '$') {
          ans++;
        } else if (isupper(board[nx][ny])) {
          if (!key[board[nx][ny] - 'A']) {
            door[board[nx][ny] - 'A'].push_back({nx, ny});
            continue;
          }
        } else if (islower(board[nx][ny])) {
          key[board[nx][ny] - 'a'] = 1;
          for (auto d : door[board[nx][ny] - 'a']) Q.push({d.X, d.Y});
          door[board[nx][ny] - 'a'].clear();
        }
        Q.push({nx, ny});
      }
    }
    cout << ans << "\n";
  }
}