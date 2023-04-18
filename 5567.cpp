// http://boj.kr/e2299acc27d447aa9f35288c731397d4
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[501];
int dist[501];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int num = 0;
  queue<int> q;
  q.push(1);
  dist[1] = 1;
  while (!q.empty()) {
    int cur = q.front();
    if (dist[cur] > 2) break;
    q.pop();
    for (int nxt : adj[cur]) {
      if (dist[nxt] != 0) continue;
      num++;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }
  cout << num;
}