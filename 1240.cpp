// http://boj.kr/e309f36ec0c147e4834fae2ed6e5f3cc
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
vector<pair<int, int>> adj[1001];
int p[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    fill(p + 1, p + n + 1, 0);
    queue<pair<int, int>> q;
    q.push({a, 0});
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (cur.X == b) {
        cout << cur.Y << '\n';
        break;
      }
      for (auto nxt : adj[cur.X]) {
        if (p[cur.X] == nxt.X) continue;
        q.push({nxt.X, cur.Y + nxt.Y});
        p[nxt.X] = cur.X;
      }
    }
  }
}