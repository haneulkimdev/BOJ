// http://boj.kr/03eb06d6bf0642fea58f6387ac211393
#include <bits/stdc++.h>
using namespace std;
int dist[1000001];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int f, s, g, u, d;
  cin >> f >> s >> g >> u >> d;
  fill(dist + 1, dist + f + 1, -1);
  queue<int> Q;
  dist[s] = 0;
  Q.push(s);
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (int nxt : {cur + u, cur - d}) {
      if (nxt < 1 || nxt > f) continue;
      if (dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      Q.push(nxt);
    }
  }
  if (dist[g] == -1)
    cout << "use the stairs";
  else
    cout << dist[g];
}