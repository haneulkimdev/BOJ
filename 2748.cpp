// http://boj.kr/36ebd68777cb4d4584e3b20cb0afdad5
#include <bits/stdc++.h>
using namespace std;

long long d[91];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  d[1] = 1;
  for (int i = 2; i <= n; i++) d[i] = d[i - 1] + d[i - 2];
  cout << d[n];
}