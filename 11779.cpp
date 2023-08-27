// http://boj.kr/a98423dc5db14e78b01057edb5a4d535
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
vector<pair<int, int>> adj[1001];
int d[1001];
int pre[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  fill(d + 1, d + n + 1, 0x7fffffff);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }
  int st, en;
  cin >> st >> en;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  d[st] = 0;
  pq.push({d[st], st});
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (d[cur.Y] != cur.X) continue;
    for (auto nxt : adj[cur.Y]) {
      if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y], nxt.Y});
      pre[nxt.Y] = cur.Y;
    }
  }
  cout << d[en] << '\n';
  vector<int> path;
  int cur = en;
  while (cur != st) {
    path.push_back(cur);
    cur = pre[cur];
  }
  path.push_back(cur);
  reverse(path.begin(), path.end());
  cout << path.size() << '\n';
  for (auto x : path) cout << x << ' ';
}