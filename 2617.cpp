// http://boj.kr/8c10c49c49464b5ca4b12e6b7c7ecd04
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj1[100];
vector<int> adj2[100];
bool vis[100];

bool solve(int st, vector<int> adj[]) {
  fill(vis + 1, vis + n + 1, false);
  queue<int> q;
  q.push(st);
  vis[st] = true;
  int cnt = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
      cnt++;
    }
  }
  return cnt >= (n + 1) / 2;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj1[u].push_back(v);
    adj2[v].push_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (solve(i, adj1) || solve(i, adj2)) ans++;
  cout << ans;
}