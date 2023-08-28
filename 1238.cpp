// http://boj.kr/d1e1dfe4a77b447da04932a1851d5e3a
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, x;
vector<pair<int, int>> adj[1001];
int d[1001][1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> x;
  for (int i = 1; i <= n; i++) fill(d[i] + 1, d[i] + n + 1, 0x7fffffff);
  while (m--) {
    int a, b, t;
    cin >> a >> b >> t;
    adj[a].push_back({t, b});
  }
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
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, d[i][x] + d[x][i]);
  cout << ans;
}