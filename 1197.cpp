// http://boj.kr/54deac4b77a54a8aa5a45cefb584ab49
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int v, e;
vector<pair<int, int>> adj[10001];
bool chk[10001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> v >> e;
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  int cnt = 0;
  int ans = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  chk[1] = true;
  for (auto nxt : adj[1]) pq.push(nxt);
  while (cnt < v - 1) {
    auto cur = pq.top();
    pq.pop();
    if (chk[cur.Y]) continue;
    ans += cur.X;
    chk[cur.Y] = true;
    cnt++;
    for (auto nxt : adj[cur.Y])
      if (!chk[nxt.Y]) pq.push(nxt);
  }
  cout << ans;
}