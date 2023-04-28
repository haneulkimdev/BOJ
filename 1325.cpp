// http://boj.kr/be3acec15c154d498c97070c077dd4f8
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[10001];
bool vis[10001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
  }
  vector<int> ans;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int num = 1;
    queue<int> q;
    q.push(i);
    vis[i] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        q.push(nxt);
        vis[nxt] = true;
        num++;
      }
    }
    if (num >= mx) {
      if (num > mx) ans.clear();
      ans.push_back(i);
      mx = num;
    }
    fill(vis + 1, vis + n + 1, false);
  }
  sort(ans.begin(), ans.end());
  for (int i : ans) cout << i << ' ';
}