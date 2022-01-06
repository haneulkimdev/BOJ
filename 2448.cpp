// http://boj.kr/a2057d77d3af4b768c0b2e0e27d8432d
#include <bits/stdc++.h>
using namespace std;

char board[3072][6144];

void func(int n, int x, int y) {
  if (n == 3) {
    board[x][y] = '*';
    board[x + 1][y - 1] = '*';
    board[x + 1][y + 1] = '*';
    board[x + 2][y - 2] = '*';
    board[x + 2][y - 1] = '*';
    board[x + 2][y] = '*';
    board[x + 2][y + 1] = '*';
    board[x + 2][y + 2] = '*';
    return;
  }
  func(n / 2, x, y);
  func(n / 2, x + n / 2, y - n / 2);
  func(n / 2, x + n / 2, y + n / 2);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) fill(board[i], board[i] + 2 * n - 1, ' ');
  func(n, 0, n - 1);
  for (int i = 0; i < n; i++) cout << board[i] << '\n';
}