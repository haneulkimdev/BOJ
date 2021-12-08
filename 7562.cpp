// http://boj.kr/129c4b3e437a4d708b6c5a9972a8c614
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[300][300];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int l;
bool OOB(int a, int b) { return a < 0 || a >= l || b < 0 || b >= l; }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int x1, y1, x2, y2;
    cin >> l;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    for (int i = 0; i < l; i++) fill(dist[i], dist[i] + l, -1);
    queue<pair<int, int>> Q;
    dist[x1][y1] = 0;
    Q.push({x1, y1});
    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      for (int dir = 0; dir < 8; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (OOB(nx, ny) || dist[nx][ny] >= 0) continue;
        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        Q.push({nx, ny});
      }
    }
    cout << dist[x2][y2] << '\n';
  }
}