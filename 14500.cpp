// http://boj.kr/8e819c7f06c54eec9aaeda404af02e24
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[500][500];
vector<vector<pair<int, int>>> tetro;

bool is_adj(pair<int, int> a, pair<int, int> b) {
  if (a.X == b.X) return abs(a.Y - b.Y) == 1;
  if (a.Y == b.Y) return abs(a.X - b.X) == 1;
  return false;
}

bool is_conn(vector<pair<int, int>> &shape) {
  bool state = false;
  for (int i = 0; i < 4; i++) {
    int cnt = 0;
    for (int j = 0; j < 4; j++)
      if (is_adj(shape[i], shape[j])) cnt++;
    if (cnt == 0) return false;
    if (cnt >= 2) state = true;
  }
  return state;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> board[i][j];
  vector<bool> brute(16);
  for (int i = 4; i < 16; i++) brute[i] = 1;
  do {
    vector<pair<int, int>> shape;
    for (int i = 0; i < 16; i++)
      if (brute[i] == 0) shape.push_back({i / 4, i % 4});
    if (is_conn(shape)) tetro.push_back(shape);
  } while (next_permutation(brute.begin(), brute.end()));
  int ans = 0;
  for (int i = 0; i <= n - 4; i++) {
    for (int j = 0; j <= m - 4; j++) {
      for (auto shape : tetro) {
        int sum = 0;
        for (auto coor : shape) sum += board[i + coor.X][j + coor.Y];
        ans = max(ans, sum);
      }
    }
  }
  cout << ans;
}