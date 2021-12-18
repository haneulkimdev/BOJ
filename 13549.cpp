// http://boj.kr/bafab6346061459292bce93d2bff0c39
#include <bits/stdc++.h>
using namespace std;
int dist[100001];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  fill(dist, dist + 100001, -1);
  deque<int> dq;
  dq.push_back(n);
  dist[n] = 0;
  while (!dq.empty()) {
    int cur = dq.front();
    dq.pop_front();
    for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
      if (nxt < 0 || nxt > 100000) continue;
      if (dist[nxt] != -1) continue;
      if (nxt == 2 * cur) {
        dq.push_front(nxt);
        dist[nxt] = dist[cur];
      } else {
        dq.push_back(nxt);
        dist[nxt] = dist[cur] + 1;
      }
    }
  }
  cout << dist[k];
}