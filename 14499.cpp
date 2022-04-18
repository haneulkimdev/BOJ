// http://boj.kr/fd2ff09772e64bb3bed3d57bb7f82555
#include <bits/stdc++.h>
using namespace std;

vector<int> dice(7);
int n, m, x, y, k;
int board[20][20];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
bool OOB(int a, int b) { return a < 0 || a >= n || b < 0 || b >= m; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> x >> y >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> board[i][j];
  while (k--) {
    int dir;
    cin >> dir;
    if (OOB(x + dx[dir], y + dy[dir])) continue;
    vector<int> tmp = dice;
    if (dir == 1) {
      tmp[1] = dice[4];
      tmp[3] = dice[1];
      tmp[4] = dice[6];
      tmp[6] = dice[3];
    } else if (dir == 2) {
      tmp[1] = dice[3];
      tmp[3] = dice[6];
      tmp[4] = dice[1];
      tmp[6] = dice[4];
    } else if (dir == 3) {
      tmp[1] = dice[5];
      tmp[2] = dice[1];
      tmp[5] = dice[6];
      tmp[6] = dice[2];
    } else if (dir == 4) {
      tmp[1] = dice[2];
      tmp[2] = dice[6];
      tmp[5] = dice[1];
      tmp[6] = dice[5];
    }
    dice = tmp;
    x += dx[dir];
    y += dy[dir];
    if (board[x][y] == 0) {
      board[x][y] = dice[6];
    } else {
      dice[6] = board[x][y];
      board[x][y] = 0;
    }
    cout << dice[1] << '\n';
  }
}