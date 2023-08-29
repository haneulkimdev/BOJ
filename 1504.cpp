// http://boj.kr/d1bd63dec8294b20b188175b5ca51903
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, e;
vector<pair<int, int>> adj[801];
const int INF = 0x7fffffff;
int d[801][801];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> e;
  for (int i = 1; i <= n; i++) fill(d[i] + 1, d[i] + n + 1, INF);
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  int u, v;
  cin >> u >> v;
  for (int i = 1; i <= n; i++) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    d[i][i] = 0;
    pq.push({d[i][i], i});
    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      if (d[i][cur.Y] != cur.X) continue;
      for (auto nxt : adj[cur.Y]) {
        if (d[i][nxt.Y] <= d[i][cur.Y] + nxt.X) continue;
        d[i][nxt.Y] = d[i][cur.Y] + nxt.X;
        pq.push({d[i][nxt.Y], nxt.Y});
      }
    }
  }
  int ans = INF;
  if (d[1][u] != INF && d[u][v] != INF && d[v][n] != INF)
    ans = min(ans, d[1][u] + d[u][v] + d[v][n]);
  if (d[1][v] != INF && d[v][u] != INF && d[u][n] != INF)
    ans = min(ans, d[1][v] + d[v][u] + d[u][n]);
  if (ans == INF)
    cout << -1;
  else
    cout << ans;
}