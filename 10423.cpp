// http://boj.kr/d4260d0a950445e0870708f4377097f5
#include <bits/stdc++.h>
using namespace std;

vector<int> p(1001, -1);

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  if (p[u] == p[v]) p[u]--;
  if (p[u] < p[v])
    p[v] = u;
  else
    p[u] = v;
  return true;
}

int n, m, k;
tuple<int, int, int> edge[100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  int cnt = 0;
  while (k--) {
    int t;
    cin >> t;
    if (merge(t, 0)) cnt++;
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge[i] = {w, u, v};
  }
  n++;
  sort(edge, edge + m);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    tie(w, u, v) = edge[i];
    if (!merge(u, v)) continue;
    ans += w;
    cnt++;
    if (cnt == n - 1) break;
  }
  cout << ans;
}