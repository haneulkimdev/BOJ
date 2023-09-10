// http://boj.kr/8ea5316b928b499984c9841aa1bf03c4
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
vector<pair<int, int>> adj[1001];
int d[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  fill(d + 1, d + n + 1, 0x7fffffff);
  cin >> m;
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
    }
  }
  cout << d[en];
}