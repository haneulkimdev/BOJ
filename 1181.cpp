// http://boj.kr/488b9fdf16b34cce9d23ae0fb7dee383
#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b) {
  if (a.size() != b.size()) return a.size() < b.size();
  return a < b;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> v;
  while (n--) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  sort(v.begin(), v.end(), cmp);
  v.erase(unique(v.begin(), v.end()), v.end());
  for (string s : v) cout << s << '\n';
}