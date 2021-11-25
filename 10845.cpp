// http://boj.kr/492b71c1bf26462cb32cb144d2571f5c
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  queue<int> Q;
  while (n--) {
    string c;
    cin >> c;
    if (c == "push") {
      int x;
      cin >> x;
      Q.push(x);
    } else if (c == "pop") {
      if (Q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << Q.front() << '\n';
        Q.pop();
      }
    } else if (c == "size") {
      cout << Q.size() << '\n';
    } else if (c == "empty") {
      cout << Q.empty() << '\n';
    } else if (c == "front") {
      if (Q.empty())
        cout << -1 << '\n';
      else
        cout << Q.front() << '\n';
    } else if (c == "back") {
      if (Q.empty())
        cout << -1 << '\n';
      else
        cout << Q.back() << '\n';
    }
  }
}