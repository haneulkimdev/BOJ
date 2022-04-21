// http://boj.kr/3854fe29fc724fa68690d3ffec8ee1d3
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, K, L;
int board[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> turn;
deque<pair<int, int>> snake;
bool OOB(int a, int b) { return a < 0 || a >= N || b < 0 || b >= N; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  cin >> K;
  while (K--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    board[a][b] = 1;
  }
  cin >> L;
  while (L--) {
    int X;
    char C;
    cin >> X >> C;
    turn.push({X, C});
  }
  snake.push_front({0, 0});
  board[0][0] = 2;
  int dir = 1;
  int time = 1;
  while (true) {
    auto head = snake.front();
    int nx = head.X + dx[dir];
    int ny = head.Y + dy[dir];
    if (OOB(nx, ny) || board[nx][ny] == 2) break;
    if (board[nx][ny] == 0) {
      auto tail = snake.back();
      snake.pop_back();
      board[tail.X][tail.Y] = 0;
    }
    snake.push_front({nx, ny});
    board[nx][ny] = 2;
    if (turn.front().X == time) {
      if (turn.front().Y == 'L')
        dir = (dir + 1) % 4;
      else
        dir = (dir + 3) % 4;
      turn.pop();
    }
    time++;
  }
  cout << time;
}