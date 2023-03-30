// http://boj.kr/d88e9614a843442d8183b7fe8775deeb
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, e, q;
  cin >> s >> e >> q;
  unordered_set<string> enter;
  unordered_set<string> leave;
  string time, name;
  while (cin >> time >> name) {
    if (time <= s)
      enter.insert(name);
    else if (time >= e && time <= q)
      leave.insert(name);
  }
  int cnt = 0;
  for (string name : enter) cnt += leave.find(name) != leave.end();
  cout << cnt;
}