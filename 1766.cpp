// http://boj.kr/bf9c8d02adf04e029eb3cd260ea30959
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32001];
int deg[32001];
int n, m;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    deg[b]++;
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 0) pq.push(i);
  while (!pq.empty()) {
    int cur = pq.top();
    pq.pop();
    cout << cur << ' ';
    for (int nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) pq.push(nxt);
    }
  }
}