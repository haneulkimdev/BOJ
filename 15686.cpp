// http://boj.kr/76f8ff38fa244d07b2aa530635a90a53
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[50][50];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) house.push_back({i, j});
      if (board[i][j] == 2) chicken.push_back({i, j});
    }
  }
  vector<bool> brute(chicken.size());
  for (int i = m; i < chicken.size(); i++) brute[i] = 1;
  int mn = 0x7fffffff;
  do {
    int dist = 0;
    for (auto h : house) {
      int tmp = 0x7fffffff;
      for (int i = 0; i < chicken.size(); i++) {
        if (brute[i]) continue;
        tmp = min(tmp, abs(h.X - chicken[i].X) + abs(h.Y - chicken[i].Y));
      }
      dist += tmp;
    }
    mn = min(mn, dist);
  } while (next_permutation(brute.begin(), brute.end()));
  cout << mn;
}