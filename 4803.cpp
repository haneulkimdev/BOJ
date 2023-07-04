// http://boj.kr/f16c20baa9604c689e5f6df8815f6edc
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[501];
int p[501];

bool dfs(int cur) {
  for (int nxt : adj[cur]) {
    if (p[cur] == nxt) continue;
    if (p[nxt] != 0) return false;
    p[nxt] = cur;
    if (!dfs(nxt)) return false;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    for (int i = 1; i <= n; i++) adj[i].clear();
    fill(p + 1, p + n + 1, 0);
    while (m--) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int num = 0;
    for (int i = 1; i <= n; i++) {
      if (p[i] != 0) continue;
      num += dfs(i);
    }
    cout << "Case " << t++ << ": ";
    if (num > 1)
      cout << "A forest of " << num << " trees.\n";
    else if (num == 1)
      cout << "There is one tree.\n";
    else
      cout << "No trees.\n";
  }
}