// http://boj.kr/a601c70d90de42e0b9505deb929992aa
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

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

int n, m;
vector<tuple<double, int, int>> edge;
pair<int, int> pos[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  cout.precision(2);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> pos[i].X >> pos[i].Y;
    for (int j = 1; j < i; j++) {
      int a = pos[i].X - pos[j].X;
      int b = pos[i].Y - pos[j].Y;
      double c = sqrt(1LL * a * a + 1LL * b * b);
      edge.push_back({c, i, j});
    }
  }
  sort(edge.begin(), edge.end());
  int cnt = 0;
  while (m--) {
    int i, j;
    cin >> i >> j;
    if (merge(i, j)) cnt++;
  }
  double ans = 0;
  for (auto [c, i, j] : edge) {
    if (!merge(i, j)) continue;
    ans += c;
    cnt++;
    if (cnt == n - 1) break;
  }
  cout << ans;
}