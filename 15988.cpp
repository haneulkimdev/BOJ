// http://boj.kr/1010ddfad24444b494282348b786bf26
#include <bits/stdc++.h>
using namespace std;

long long d[1000001];
int mod = 1000000009;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  d[1] = 1;
  d[2] = 2;
  d[3] = 4;
  for (int i = 4; i < 1000001; i++)
    d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % mod;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << d[n] << '\n';
  }
}