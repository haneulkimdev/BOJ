// http://boj.kr/31c7202f0e7944ff9faeb6bb20f6ab40
#include <bits/stdc++.h>
using namespace std;

int n;
int adj[100][100];
bool vis[100][100];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> adj[i][j];
  for (int i = 0; i < n; i++) {
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int nxt = 0; nxt < n; nxt++) {
        if (adj[cur][nxt] == 0 || vis[i][nxt]) continue;
        q.push(nxt);
        vis[i][nxt] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << vis[i][j] << ' ';
    cout << '\n';
  }
}