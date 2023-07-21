// http://boj.kr/ca57784092364a1bad4166d56680a1a5
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int deg[1001];
int n, m;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> a;
    if (a == 0) continue;
    cin >> b;
    while (--a) {
      cin >> c;
      adj[b].push_back(c);
      deg[c]++;
      b = c;
    }
  }
  queue<int> q;
  vector<int> result;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 0) q.push(i);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    result.push_back(cur);
    for (auto nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
  if (result.size() != n)
    cout << 0;
  else
    for (auto x : result) cout << x << '\n';
}