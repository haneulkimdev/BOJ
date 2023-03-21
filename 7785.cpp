// http://boj.kr/b79bf07741bd4418aa216b2d86c21c48
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string name, log;
    cin >> name >> log;
    if (log == "enter")
      s.insert(name);
    else
      s.erase(name);
  }
  vector<string> ans(s.begin(), s.end());
  sort(ans.begin(), ans.end(), greater<string>());
  for (auto x : ans) cout << x << '\n';
}