// http://boj.kr/2367d2636e1e436e99eb4bbf305b7d1f
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string init;
  cin >> init;
  list<char> L;
  for (auto c : init) L.push_back(c);
  auto cursor = L.end();
  int m;
  cin >> m;
  while (m--) {
    char op;
    cin >> op;
    if (op == 'L') {
      if (cursor != L.begin()) cursor--;
    } else if (op == 'D') {
      if (cursor != L.end()) cursor++;
    } else if (op == 'B') {
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
    } else if (op == 'P') {
      char add;
      cin >> add;
      L.insert(cursor, add);
    }
  }
  for (auto c : L) cout << c;
}