// http://boj.kr/74ba77089d11429aa69474b9240fd5ec
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

int n, m;
vector<tuple<int, int, int>> edge;

int solve() {
  int cnt = 0;
  int k = 0;
  for (auto [c, a, b] : edge) {
    if (!merge(a, b)) continue;
    k += c;
    cnt++;
    if (cnt == n) break;
  }
  return k * k;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m + 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge.push_back({!c, a, b});
  }
  int ans = 0;
  sort(edge.begin(), edge.end(), greater<tuple<int, int, int>>());
  ans += solve();
  fill(p.begin(), p.end(), -1);
  sort(edge.begin(), edge.end());
  ans -= solve();
  cout << ans;
}