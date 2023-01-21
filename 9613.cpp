// http://boj.kr/edf7a5d7f1cd4d46875f9ebfc5a2b73d
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100];

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) ans += gcd(a[i], a[j]);
    cout << ans << '\n';
  }
}