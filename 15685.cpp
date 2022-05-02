// http://boj.kr/523508c1ca004e8f9d7218fc447ba367
#include <bits/stdc++.h>
using namespace std;

int n;
int board[101][101];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while (n--) {
    int x, y, d, g;
    cin >> x >> y >> d >> g;
    board[x][y] = 1;
    vector<int> v;
    v.push_back(d);
    while (g--) {
      int sz = v.size();
      for (int i = sz - 1; i >= 0; i--) v.push_back((v[i] + 1) % 4);
    }
    for (int dir : v) {
      if (dir == 0) x++;
      if (dir == 1) y--;
      if (dir == 2) x--;
      if (dir == 3) y++;
      board[x][y] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++)
      if (board[i][j] && board[i + 1][j] && board[i + 1][j + 1] && board[i][j + 1])
        ans++;
  cout << ans;
}