// http://boj.kr/665c4dd930d046a88d5a510342930528
#include <bits/stdc++.h>
using namespace std;

vector<bool> state(10001, true);
void sieve(int n) {
  state[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (!state[i]) continue;
    for (int j = i * i; j <= n; j += i)
      state[j] = false;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  sieve(10000);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = n / 2; i > 1; i--) {
      if (state[i] && state[n - i]) {
        cout << i << ' ' << n - i << '\n';
        break;
      }
    }
  }
}