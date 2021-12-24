// http://boj.kr/b17b3551c7af45ac8ab936e9e5cfd5df
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[2][500001];
int main(void) {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < 2; i++) fill(dist[i], dist[i] + 500001, -1);
  queue<pair<int, int>> Q;
  Q.push({0, n});
  dist[0][n] = 0;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int nxt : {cur.Y - 1, cur.Y + 1, 2 * cur.Y}) {
      if (nxt < 0 || nxt > 500000) continue;
      if (dist[1 - cur.X][nxt] >= 0) continue;
      Q.push({1 - cur.X, nxt});
      dist[1 - cur.X][nxt] = dist[cur.X][cur.Y] + 1;
    }
  }
  int ans = 0x7fffffff;
  int time = 0;
  while (k <= 500000) {
    if (dist[time % 2][k] >= 0 && dist[time % 2][k] <= time)
      ans = min(ans, time);
    time++;
    k += time;
  }
  if (ans == 0x7fffffff) ans = -1;
  cout << ans;
}