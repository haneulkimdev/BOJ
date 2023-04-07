// http://boj.kr/94817fa77b0f4eea8697dd8f65290911
#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> s;
set<pair<int, int>> g2s[101];
int p2l[100001];
int p2g[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int p, l, g;
    cin >> p >> l >> g;
    p2l[p] = l;
    p2g[p] = g;
    s.insert({l, p});
    g2s[g].insert({l, p});
  }
  int m;
  cin >> m;
  while (m--) {
    string query;
    cin >> query;
    if (query == "recommend") {
      int g, x;
      cin >> g >> x;
      if (x == 1) {
        auto it = prev(g2s[g].end());
        cout << it->second << '\n';
      } else if (x == -1) {
        auto it = g2s[g].begin();
        cout << it->second << '\n';
      }
    } else if (query == "recommend2") {
      int x;
      cin >> x;
      if (x == 1) {
        auto it = prev(s.end());
        cout << it->second << '\n';
      } else if (x == -1) {
        auto it = s.begin();
        cout << it->second << '\n';
      }
    } else if (query == "recommend3") {
      int x, l;
      cin >> x >> l;
      auto it = s.lower_bound({l, 0});
      if (x == 1) {
        if (it != s.end())
          cout << it->second << '\n';
        else
          cout << -1 << '\n';
      } else if (x == -1) {
        if (it != s.begin())
          cout << prev(it)->second << '\n';
        else
          cout << -1 << '\n';
      }
    } else if (query == "add") {
      int p, l, g;
      cin >> p >> l >> g;
      p2l[p] = l;
      p2g[p] = g;
      s.insert({l, p});
      g2s[g].insert({l, p});
    } else if (query == "solved") {
      int p;
      cin >> p;
      s.erase({p2l[p], p});
      g2s[p2g[p]].erase({p2l[p], p});
    }
  }
}