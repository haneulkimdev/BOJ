// http://boj.kr/6cc35931c5f341f99ac1b7e5827d1fe8
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  vector<string> v;
  for (int i = 0; i < s.size(); i++) v.push_back(s.substr(i));
  sort(v.begin(), v.end());
  for (string s : v) cout << s << '\n';
}