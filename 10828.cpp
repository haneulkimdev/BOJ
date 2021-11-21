// http://boj.kr/ecf4d0c7b0f8483dbe41bf46d2bbff8d
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> S;
  while (n--) {
    string c;
    cin >> c;
    if (c == "push") {
      int x;
      cin >> x;
      S.push(x);
    } else if (c == "pop") {
      if (S.empty()) {
        cout << -1 << '\n';
      } else {
        cout << S.top() << '\n';
        S.pop();
      }
    } else if (c == "size") {
      cout << S.size() << '\n';
    } else if (c == "empty") {
      cout << S.empty() << '\n';
    } else if (c == "top") {
      if (S.empty())
        cout << -1 << '\n';
      else
        cout << S.top() << '\n';
    }
  }
}