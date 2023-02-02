// http://boj.kr/01ab235899334f9b915e49535dc27239
#include <bits/stdc++.h>
using namespace std;

vector<bool> state(1000001, true);
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
  sieve(1000000);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i <= n / 2; i++)
      if (state[i] && state[n - i]) cnt++;
    cout << cnt << '\n';
  }
}