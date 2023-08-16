// http://boj.kr/d5776d8e61744bb08c9ec8d3ab120b1d
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<int> p(100000, -1);

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

int n;
vector<tuple<int, int, int>> edge;
pair<int, int> x[100000];
pair<int, int> y[100000];
pair<int, int> z[100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i].X >> y[i].X >> z[i].X;
    x[i].Y = i;
    y[i].Y = i;
    z[i].Y = i;
  }
  sort(x, x + n);
  sort(y, y + n);
  sort(z, z + n);
  for (int i = 1; i < n; i++) {
    edge.push_back({abs(x[i - 1].X - x[i].X), x[i - 1].Y, x[i].Y});
    edge.push_back({abs(y[i - 1].X - y[i].X), y[i - 1].Y, y[i].Y});
    edge.push_back({abs(z[i - 1].X - z[i].X), z[i - 1].Y, z[i].Y});
  }
  sort(edge.begin(), edge.end());
  int cnt = 0;
  int ans = 0;
  for (auto [cost, a, b] : edge) {
    if (!merge(a, b)) continue;
    ans += cost;
    cnt++;
    if (cnt == n - 1) break;
  }
  cout << ans;
}