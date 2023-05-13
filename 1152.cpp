// http://boj.kr/bf85a7bca1874a738167d5e496f42a85
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  getline(cin, s);
  stringstream ss(s);
  int cnt = 0;
  string w;
  while (ss >> w) cnt++;
  cout << cnt;
}