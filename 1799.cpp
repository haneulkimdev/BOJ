// http://boj.kr/234a1e2facaf4cc0b46d10cb2008b39e
#include <bits/stdc++.h>
using namespace std;

int n;
int board[10][10];
bool is_used1[19];
bool is_used2[19];
int ans[2];

void func(int x, int y, int cnt, int color) {
  if (x >= n) {
    ans[color] = max(ans[color], cnt);
    return;
  }
  if (y >= n) {
    x++;
    if (y % 2 == 0)
      y = 1;
    else
      y = 0;
  }
  if (board[x][y] == 1 && !is_used1[x + y] && !is_used2[x - y + n - 1]) {
    is_used1[x + y] = 1;
    is_used2[x - y + n - 1] = 1;
    func(x, y + 2, cnt + 1, color);
    is_used1[x + y] = 0;
    is_used2[x - y + n - 1] = 0;
  }
  func(x, y + 2, cnt, color);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> board[i][j];
  func(0, 0, 0, 0);
  func(0, 1, 0, 1);
  cout << ans[0] + ans[1];
}