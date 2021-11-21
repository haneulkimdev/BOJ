// http://boj.kr/a7a22045f8f94396ae20179298a17b65
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  stack<int> S;
  while (k--) {
    int t;
    cin >> t;
    if (t == 0)
      S.pop();
    else
      S.push(t);
  }
  int ans = 0;
  while (!S.empty()) {
    ans += S.top();
    S.pop();
  }
  cout << ans;
}