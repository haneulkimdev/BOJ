// http://boj.kr/75f23f4447f640398141428834cc8337
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> S;
  long long ans = 0;
  while (n--) {
    int h;
    cin >> h;
    while (!S.empty() && S.top() <= h) S.pop();
    ans += S.size();
    S.push(h);
  }
  cout << ans;
}