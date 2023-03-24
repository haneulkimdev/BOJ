// http://boj.kr/a9a0326f430f439e94427837dcc51c32
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
  return a.Y < b.Y;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, l;
  cin >> k >> l;
  unordered_map<string, int> m;
  for (int i = 0; i < l; i++) {
    string s;
    cin >> s;
    m[s] = i;
  }
  vector<pair<string, int>> ans(m.begin(), m.end());
  sort(ans.begin(), ans.end(), cmp);
  for (int i = 0; i < min(k, (int)ans.size()); i++) cout << ans[i].X << '\n';
}