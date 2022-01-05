// http://boj.kr/498f407fc81e446fabcf0c3a96ace82b
#include <bits/stdc++.h>
using namespace std;

char board[2187][2188];

void func(int n, int x, int y) {
  if (n == 1) {
    board[x][y] = '*';
    return;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) continue;
      func(n / 3, x + i * n / 3, y + j * n / 3);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) fill(board[i], board[i] + n, ' ');
  func(n, 0, 0);
  for (int i = 0; i < n; i++) cout << board[i] << '\n';
}