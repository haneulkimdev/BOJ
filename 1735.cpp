// http://boj.kr/17c19e7e0fa5427e8fbe5001a7131230
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int numer1, denom1, numer2, denom2;
  cin >> numer1 >> denom1 >> numer2 >> denom2;
  int a = numer1 * denom2 + denom1 * numer2;
  int b = denom1 * denom2;
  int g = gcd(a, b);
  cout << a / g << ' ' << b / g;
}