// http://boj.kr/4e9c14aded45402eaab17c964866a51e
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[101];
bool vis[101];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int num = 0;
  queue<int> q;
  q.push(1);
  vis[1] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : adj[cur]) {
      if (vis[nxt]) continue;
      num++;
      q.push(nxt);
      vis[nxt] = true;
    }
  }
  cout << num;
}