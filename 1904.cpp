// http://boj.kr/de352c4a8d7a4a4489df17a61ab94a09
#include <bits/stdc++.h>
using namespace std;

int d[1000001];
int mod = 15746;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  d[0] = 1;
  d[1] = 1;
  for (int i = 2; i <= n; i++) d[i] = (d[i - 1] + d[i - 2]) % mod;
  cout << d[n];
}