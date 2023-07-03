// http://boj.kr/0bfdff800e2f4e9ca64f83790370c194
#include <bits/stdc++.h>
using namespace std;

int n, r, q;
vector<int> adj[100001];
int p[100001];
int d[100001];

int dfs(int cur) {
  d[cur] = 1;
  for (int nxt : adj[cur]) {
    if (p[cur] == nxt) continue;
    p[nxt] = cur;
    d[cur] += dfs(nxt);
  }
  return d[cur];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> r >> q;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(r);
  while (q--) {
    int u;
    cin >> u;
    cout << d[u] << '\n';
  }
}