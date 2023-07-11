// http://boj.kr/a1fe371e232648f88e3b84765f11c938
#include <bits/stdc++.h>
using namespace std;

int n, m;
int score[100001];
vector<int> child[100001];

void dfs(int cur) {
  for (int nxt : child[cur]) {
    score[nxt] += score[cur];
    dfs(nxt);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    if (p == -1) continue;
    child[p].push_back(i);
  }
  while (m--) {
    int i, w;
    cin >> i >> w;
    score[i] += w;
  }
  dfs(1);
  for (int i = 1; i <= n; i++) cout << score[i] << ' ';
}