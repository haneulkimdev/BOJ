// http://boj.kr/66d40798b65a4fa79d8b39a97ea61e0f
#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<int> adj[20001];
int depth[20001];

bool solve() {
  for (int i = 1; i <= v; i++) {
    if (depth[i] != -1) continue;
    queue<int> q;
    q.push(i);
    depth[i] = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int nxt : adj[cur]) {
        if (depth[nxt] != -1) {
          if ((depth[cur] - depth[nxt]) % 2 == 0) return false;
          continue;
        }
        q.push(nxt);
        depth[nxt] = depth[cur] + 1;
      }
    }
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  while (k--) {
    cin >> v >> e;
    for (int i = 1; i <= v; i++) {
      depth[i] = -1;
      adj[i].clear();
    }
    while (e--) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}