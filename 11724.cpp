// http://boj.kr/1f4d3d80802a491d9acd63494ca4062b
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool vis[1001];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int num = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    num++;
    queue<int> q;
    q.push(i);
    vis[i] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        q.push(nxt);
        vis[nxt] = true;
      }
    }
  }
  cout << num;
}