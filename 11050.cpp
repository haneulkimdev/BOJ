// http://boj.kr/5f3353cedd2f4481b8887be78baf69a5
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int ans = 1;
  for (int i = n; i > 0; i--) ans *= i;
  for (int i = k; i > 0; i--) ans /= i;
  for (int i = n - k; i > 0; i--) ans /= i;
  cout << ans;
}