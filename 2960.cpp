// http://boj.kr/8cdd0a1bfb5d44789d9c0d83e0daafb1
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<bool> state(n + 1, true);
  state[1] = false;
  for (int i = 2; i <= n; i++) {
    if (!state[i]) continue;
    for (int j = i; j <= n; j += i) {
      if (!state[j]) continue;
      state[j] = false;
      k--;
      if (k == 0) {
        cout << j;
        return 0;
      }
    }
  }
}