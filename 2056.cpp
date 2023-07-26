// http://boj.kr/eb1edfd7e9f94e5b8a8f17c7cf5e473a
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int deg[10001];
int n;
int a[10001];
int d[10001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int b, c;
    cin >> b;
    while (b--) {
      cin >> c;
      adj[c].push_back(i);
      deg[i]++;
    }
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      q.push(i);
      d[i] = a[i];
    }
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
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, d[i]);
  cout << ans;
}