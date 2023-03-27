// http://boj.kr/2e0c6f5f26c4428e813f4a348afa7e91
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_map<string, int> m;
    while (n--) {
      string name, category;
      cin >> name >> category;
      m[category]++;
    }
    int ans = 1;
    for (auto e : m) ans *= e.second + 1;
    cout << ans - 1 << '\n';
  }
}