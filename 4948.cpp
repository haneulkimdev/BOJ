// http://boj.kr/4d7fb5e1fd564d50b0a13199e1e664a3
#include <bits/stdc++.h>
using namespace std;

vector<bool> state(246913, true);
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
  sieve(246912);
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    int cnt = 0;
    for (int i = n + 1; i <= 2 * n; i++) cnt += state[i];
    cout << cnt << '\n';
  }
}