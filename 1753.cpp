// http://boj.kr/c7af5dcd662a4029a1589dd5ed62787f
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int v, e;
vector<pair<int, int>> adj[20001];
int d[20001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> v >> e;
  fill(d + 1, d + v + 1, 0x7fffffff);
  int k;
  cin >> k;
  while (e--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  d[k] = 0;
  pq.push({d[k], k});
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (d[cur.Y] != cur.X) continue;
    for (auto nxt : adj[cur.Y]) {
      if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y], nxt.Y});
    }
  }
  for (int i = 1; i <= v; i++)
    if (d[i] == 0x7fffffff)
      cout << "INF\n";
    else
      cout << d[i] << '\n';
}