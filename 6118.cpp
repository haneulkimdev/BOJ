// http://boj.kr/8df48d02278c4731a6b8853f6a7d15a7
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[20001];
int dist[20001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> v;
  int mx = 0;
  fill(dist + 1, dist + n + 1, -1);
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
      if (dist[nxt] >= mx) {
        if (dist[nxt] > mx) v.clear();
        v.push_back(nxt);
        mx = dist[nxt];
      }
    }
  }
  sort(v.begin(), v.end());
  cout << v[0] << ' ' << mx << ' ' << v.size();
}