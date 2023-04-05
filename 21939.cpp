// http://boj.kr/86998020cdb24715bc38b84b9e26bc63
#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> s;
int p2l[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int p, l;
    cin >> p >> l;
    p2l[p] = l;
    s.insert({l, p});
  }
  int m;
  cin >> m;
  while (m--) {
    string query;
    cin >> query;
    if (query == "recommend") {
      int x;
      cin >> x;
      if (x == 1) {
        auto it = prev(s.end());
        cout << it->second << '\n';
      } else if (x == -1) {
        auto it = s.begin();
        cout << it->second << '\n';
      }
    } else if (query == "add") {
      int p, l;
      cin >> p >> l;
      p2l[p] = l;
      s.insert({l, p});
    } else if (query == "solved") {
      int p;
      cin >> p;
      s.erase({p2l[p], p});
    }
  }
}