// http://boj.kr/12e6308303ac430884f709240c200283
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[101];
int dist[101];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int mnidx = 0;
  int mnval = 0x7fffffff;
  for (int i = 1; i <= n; i++) {
    fill(dist + 1, dist + n + 1, -1);
    int val = 0;
    queue<int> q;
    q.push(i);
    dist[i] = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int nxt : adj[cur]) {
        if (dist[nxt] != -1) continue;
        q.push(nxt);
        dist[nxt] = dist[cur] + 1;
        val += dist[nxt];
      }
    }
    if (val < mnval) {
      mnidx = i;
      mnval = val;
    }
  }
  cout << mnidx;
}