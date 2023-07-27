// http://boj.kr/ccdaf8eaa961436fa01f98b66ee3d3f9
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int deg[1001];
int a[1001];
int d[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) adj[i].clear();
    fill(deg + 1, deg + n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (k--) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      deg[y]++;
    }
    int w;
    cin >> w;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (deg[i] == 0) q.push(i);
      d[i] = a[i];
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int nxt : adj[cur]) {
        deg[nxt]--;
        if (deg[nxt] == 0) q.push(nxt);
        d[nxt] = max(d[nxt], d[cur] + a[nxt]);
      }
    }
    cout << d[w] << '\n';
  }
}