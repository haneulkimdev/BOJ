// http://boj.kr/7957e185e5af401f9342d44d1a0401d2
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  while (n--) {
    string a;
    cin >> a;
    stack<char> s;
    for (auto c : a) {
      if (!s.empty() && s.top() == c)
        s.pop();
      else
        s.push(c);
    }
    if (s.empty()) ans++;
  }
  cout << ans;
}