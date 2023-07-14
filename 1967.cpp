// http://boj.kr/59c7a221c724404da90d950ef0548b14
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int ans = 0;
int n;
vector<pair<int, int>> child[10001];

int dfs(int cur) {
  int first = 0;
  int second = 0;
  for (auto nxt : child[cur]) {
    int dist = dfs(nxt.X) + nxt.Y;
    if (dist > first) {
      second = first;
      first = dist;
    } else if (dist > second) {
      second = dist;
    }
  }
  ans = max(ans, first + second);
  return first;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    child[a].push_back({b, c});
  }
  dfs(1);
  cout << ans;
}