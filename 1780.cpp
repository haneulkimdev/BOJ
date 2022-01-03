// http://boj.kr/0ca45922e3b448629e2fd9526cbb7bb6
#include <bits/stdc++.h>
using namespace std;

int paper[2187][2187];
int ans[3];

bool chk(int n, int x, int y) {
  for (int i = x; i < x + n; i++)
    for (int j = y; j < y + n; j++)
      if (paper[i][j] != paper[x][y]) return false;
  return true;
}

void func(int n, int x, int y) {
  if (chk(n, x, y)) {
    ans[paper[x][y] + 1]++;
    return;
  }
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) func(n / 3, x + i * n / 3, y + j * n / 3);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> paper[i][j];
  func(n, 0, 0);
  for (int i = 0; i < 3; i++) cout << ans[i] << '\n';
}