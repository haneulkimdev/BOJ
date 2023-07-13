// http://boj.kr/1f6f72981ad442bba9286af802b171b0
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[1000001];
int p[1000001];
int d[1000001][2];

void dfs(int cur) {
  d[cur][0] = 1;
  for (int nxt : adj[cur]) {
    if (p[cur] == nxt) continue;
    p[nxt] = cur;
    dfs(nxt);
    d[cur][0] += min(d[nxt][0], d[nxt][1]);
    d[cur][1] += d[nxt][0];
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  cout << min(d[1][0], d[1][1]);
}