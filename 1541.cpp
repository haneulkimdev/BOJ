// http://boj.kr/f273992ac939443a85039ed6cd975d72
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = 0;
  int tmp = 0;
  int sign = 1;
  for (auto c : s) {
    if (c == '+' || c == '-') {
      ans += tmp * sign;
      tmp = 0;
      if (c == '-') sign = -1;
      continue;
    }
    tmp *= 10;
    tmp += c - '0';
  }
  ans += tmp * sign;
  cout << ans;
}