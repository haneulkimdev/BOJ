// http://boj.kr/83c83052c75a4446ba018ba993436aad
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  unordered_map<string, string> s2p;
  while (n--) {
    string site, password;
    cin >> site >> password;
    s2p[site] = password;
  }
  while (m--) {
    string site;
    cin >> site;
    cout << s2p[site] << '\n';
  }
}