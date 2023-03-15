// http://boj.kr/5a631d13caa64e7ea5c1ae304b89e84b
#include <bits/stdc++.h>
using namespace std;

int n, tot, cnt;

vector<int> sieve(int n) {
  vector<int> primes;
  vector<bool> state(n + 1, true);
  state[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (!state[i]) continue;
    for (int j = i * i; j <= n; j += i) state[j] = false;
  }
  for (int i = 2; i <= n; i++) {
    if (state[i]) primes.push_back(i);
  }
  return primes;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> primes = sieve(n);
  if (!primes.empty()) tot = primes[0];
  int en = 0;
  for (int st = 0; st < primes.size(); st++) {
    while (en < primes.size() && tot < n) {
      en++;
      if (en != primes.size()) tot += primes[en];
    }
    if (en == primes.size()) break;
    cnt += tot == n;
    tot -= primes[st];
  }
  cout << cnt;
}