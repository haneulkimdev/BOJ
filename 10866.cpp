// http://boj.kr/235e97b5e6ee48f984281d7605b52fcb
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  deque<int> DQ;
  while (n--) {
    string c;
    cin >> c;
    if (c == "push_front") {
      int x;
      cin >> x;
      DQ.push_front(x);
    } else if (c == "push_back") {
      int x;
      cin >> x;
      DQ.push_back(x);
    } else if (c == "pop_front") {
      if (DQ.empty()) {
        cout << -1 << '\n';
      } else {
        cout << DQ.front() << '\n';
        DQ.pop_front();
      }
    } else if (c == "pop_back") {
      if (DQ.empty()) {
        cout << -1 << '\n';
      } else {
        cout << DQ.back() << '\n';
        DQ.pop_back();
      }
    } else if (c == "size") {
      cout << DQ.size() << '\n';
    } else if (c == "empty") {
      cout << DQ.empty() << '\n';
    } else if (c == "front") {
      if (DQ.empty())
        cout << -1 << '\n';
      else
        cout << DQ.front() << '\n';
    } else if (c == "back") {
      if (DQ.empty())
        cout << -1 << '\n';
      else
        cout << DQ.back() << '\n';
    }
  }
}