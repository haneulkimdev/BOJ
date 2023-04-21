// http://boj.kr/4df65fff0b4c43f7abbc10141e775598
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[51];
int dist[51];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while (true) {
    int u, v;
    cin >> u >> v;
    if (u == -1 && v == -1) break;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> cand;
  int mn = 0x7fffffff;
  for (int i = 1; i <= n; i++) {
    fill(dist + 1, dist + n + 1, -1);
    int val = 0;
    queue<int> q;
    q.push(i);
    dist[i] = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int nxt : adj[cur]) {
        if (dist[nxt] != -1) continue;
        q.push(nxt);
        dist[nxt] = dist[cur] + 1;
        val = max(val, dist[nxt]);
      }
    }
    if (val <= mn) {
      if (val < mn) cand.clear();
      cand.push_back(i);
      mn = val;
    }
  }
  cout << mn << ' ' << cand.size() << '\n';
  for (int i : cand) cout << i << ' ';
}