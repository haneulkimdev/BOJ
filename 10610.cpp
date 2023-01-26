// http://boj.kr/d92fd0d36c514d829ce8ad6edf0f499a
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  sort(s.begin(), s.end(), greater<char>());
  int sum = 0;
  for (int i = 0; i < s.size(); i++) sum += s[i] - '0';
  if (sum % 3 == 0 && s.back() == '0')
    cout << s;
  else
    cout << -1;
}