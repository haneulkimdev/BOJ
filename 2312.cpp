// http://boj.kr/7a2a32718d4a49dd88eeaf19c257529e
#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
  vector<int> primes;
  vector<bool> state(n + 1, true);
  state[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (!state[i]) continue;
    for (int j = i * i; j <= n; j += i)
      state[j] = false;
  }
  for (int i = 2; i <= n; i++) {
    if (state[i]) primes.push_back(i);
  }
  return primes;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> primes = sieve(100000);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int p : primes) {
      int cnt = 0;
      while (n % p == 0) {
        cnt++;
        n /= p;
      }
      if (cnt > 0) cout << p << ' ' << cnt << '\n';
    }
  }
}