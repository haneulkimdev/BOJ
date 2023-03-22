// http://boj.kr/ff873b0403c344fe95fabc5aee44c71a
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> s2i;
string i2s[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> i2s[i];
    s2i[i2s[i]] = i;
  }
  while (m--) {
    string query;
    cin >> query;
    if (isdigit(query[0]))
      cout << i2s[stoi(query)] << '\n';
    else
      cout << s2i[query] << '\n';
  }
}