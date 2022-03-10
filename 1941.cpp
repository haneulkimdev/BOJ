// http://boj.kr/c51e762c317742db8cbcf895552ffcf1
#include <bits/stdc++.h>
using namespace std;

string board[5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool OOB(int a, int b) { return a < 0 || a >= 5 || b < 0 || b >= 5; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 5; i++) cin >> board[i];
  vector<bool> brute(25);
  for (int i = 7; i < 25; i++) brute[i] = 1;
  int ans = 0;
  do {
    vector<bool> vis(25);
    int st = 0;
    while (brute[st]) st++;
    queue<int> Q;
    Q.push(st);
    vis[st] = 1;
    int cnt1 = 0;
    int cnt2 = 0;
    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();
      int curX = cur / 5;
      int curY = cur % 5;
      if (board[curX][curY] == 'S')
        cnt1++;
      else
        cnt2++;
      for (int dir = 0; dir < 4; dir++) {
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if (OOB(nx, ny) || vis[5 * nx + ny] || brute[5 * nx + ny]) continue;
        Q.push(5 * nx + ny);
        vis[5 * nx + ny] = 1;
      }
      if (cnt1 + cnt2 == 7 && cnt1 >= 4) ans++;
    }
  } while (next_permutation(brute.begin(), brute.end()));
  cout << ans;
}