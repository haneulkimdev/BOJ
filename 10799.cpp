// http://boj.kr/1b18d6a7c7e4467894757776496127bb
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a;
  cin >> a;
  stack<char> s;
  int ans = 0;
  int sz = a.length();
  for (int i = 0; i < sz; i++) {
    if (a[i] == '(') {
      s.push(a[i]);
    } else if (a[i] == ')') {
      s.pop();
      if (a[i - 1] == '(')
        ans += s.size();
      else
        ans++;
    }
  }
  cout << ans;
}