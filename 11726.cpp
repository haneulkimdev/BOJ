// http://boj.kr/ec966daa703f499991faba24dbaf2be7
#include <bits/stdc++.h>
using namespace std;

int d[1001];
int mod = 10007;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  d[1] = 1;
  d[2] = 2;
  for (int i = 3; i <= n; i++) d[i] = (d[i - 1] + d[i - 2]) % mod;
  cout << d[n];
}