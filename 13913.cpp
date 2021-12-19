// http://boj.kr/3bb62b72acba427eb3c3b7e114277426
#include <bits/stdc++.h>
using namespace std;
int dist[100001];
int pre[100001];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  fill(dist, dist + 100001, -1);
  queue<int> Q;
  Q.push(n);
  dist[n] = 0;
  while (dist[k] == -1) {
    int cur = Q.front();
    Q.pop();
    for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
      if (nxt < 0 || nxt > 100001) continue;
      if (dist[nxt] != -1) continue;
      Q.push(nxt);
      dist[nxt] = dist[cur] + 1;
      pre[nxt] = cur;
    }
  }
  deque<int> dq = {k};
  while (dq.front() != n) dq.push_front(pre[dq.front()]);
  cout << dist[k] << '\n';
  for (int i : dq) cout << i << ' ';
}