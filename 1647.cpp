// http://boj.kr/56e10016b0b94c2c96413c27a78c7889
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
vector<pair<int, int>> adj[100001];
bool chk[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  int mx = 0;
  int cnt = 0;
  int ans = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  chk[1] = true;
  for (auto nxt : adj[1]) pq.push(nxt);
  while (cnt < n - 1) {
    auto cur = pq.top();
    pq.pop();
    if (chk[cur.Y]) continue;
    mx = max(mx, cur.X);
    ans += cur.X;
    chk[cur.Y] = true;
    cnt++;
    for (auto nxt : adj[cur.Y]) pq.push(nxt);
  }
  cout << ans - mx;
}