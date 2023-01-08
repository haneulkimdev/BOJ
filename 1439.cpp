// http://boj.kr/c357004fe1c5443090ef5a2744bdba57
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 1; i < s.size(); i++)
    if (s[i] != s[i - 1]) cnt++;
  if (cnt % 2 == 0)
    cout << cnt / 2;
  else
    cout << cnt / 2 + 1;
}