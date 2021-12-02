// http://boj.kr/4ba4812d7eaa4f38bc3166839f35bb9e
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a;
  cin >> a;
  stack<char> s;
  int ans = 0;
  int tmp = 1;
  int sz = a.length();
  for (int i = 0; i < sz; i++) {
    if (a[i] == '(') {
      s.push(a[i]);
      tmp *= 2;
    } else if (a[i] == '[') {
      s.push(a[i]);
      tmp *= 3;
    } else if (a[i] == ')') {
      if (s.empty() || s.top() != '(') {
        cout << 0;
        return 0;
      }
      s.pop();
      if (a[i - 1] == '(') ans += tmp;
      tmp /= 2;
    } else if (a[i] == ']') {
      if (s.empty() || s.top() != '[') {
        cout << 0;
        return 0;
      }
      s.pop();
      if (a[i - 1] == '[') ans += tmp;
      tmp /= 3;
    }
  }
  if (s.empty())
    cout << ans;
  else
    cout << 0;
}