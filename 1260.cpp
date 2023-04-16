// http://boj.kr/41dde00dfe3446929d5a99cd9f44fdeb
#include <bits/stdc++.h>
using namespace std;

int n, m, st;
vector<int> adj[1001];
bool vis[1001];

void dfs(int cur) {
  vis[cur] = true;
  cout << cur << ' ';
  for (auto nxt : adj[cur]) {
    if (vis[nxt]) continue;
    dfs(nxt);
  }
}

void bfs() {
  queue<int> q;
  q.push(st);
  vis[st] = true;
  while (!q.empty()) {
    int cur = q.front();
    cout << cur << ' ';
    q.pop();
    for (auto nxt : adj[cur]) {
      if (vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> st;
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
  dfs(st);
  cout << '\n';
  fill(vis + 1, vis + n + 1, false);
  bfs();
}