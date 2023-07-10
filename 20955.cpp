// http://boj.kr/8f0ea336fdaf45448e9033695f658da5
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100001];
bool vis[100001];

void dfs(int cur) {
  if (vis[cur]) return;
  vis[cur] = true;
  for (auto nxt : adj[cur]) dfs(nxt);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    dfs(i);
    cnt++;
  }
  cout << (cnt - 1) + (m + cnt - 1) - (n - 1);
}