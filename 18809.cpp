// http://boj.kr/778bbf4db0ad4fa88dfad79405156268
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, g, r;
int board[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> cand;
int candsz;
const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;
int brute[10];
bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= m; }

int func() {
  pair<int, int> state[50][50];
  queue<pair<int, int>> Q;
  for (int i = 0; i < candsz; i++) {
    if (brute[i] == GREEN || brute[i] == RED) {
      state[cand[i].X][cand[i].Y] = {0, brute[i]};
      Q.push(cand[i]);
    }
  }
  int cnt = 0;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    int cur_time = state[cur.X][cur.Y].X;
    int cur_color = state[cur.X][cur.Y].Y;
    if (cur_color == FLOWER) continue;
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (OOB(nx, ny) || board[nx][ny] == 0) continue;
      if (state[nx][ny].Y == EMPTY) {
        state[nx][ny] = {cur_time + 1, cur_color};
        Q.push({nx, ny});
      } else if (state[nx][ny].Y == GREEN) {
        if (cur_color == RED && state[nx][ny].X == cur_time + 1) {
          state[nx][ny].Y = FLOWER;
          cnt++;
        }
      } else if (state[nx][ny].Y == RED) {
        if (cur_color == GREEN && state[nx][ny].X == cur_time + 1) {
          state[nx][ny].Y = FLOWER;
          cnt++;
        }
      }
    }
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> g >> r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) cand.push_back({i, j});
    }
  }
  candsz = cand.size();
  fill(brute + candsz - g - r, brute + candsz - r, GREEN);
  fill(brute + candsz - r, brute + candsz, RED);
  int mx = 0;
  do {
    mx = max(mx, func());
  } while (next_permutation(brute, brute + candsz));
  cout << mx;
}