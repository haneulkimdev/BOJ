// http://boj.kr/4e5066f7f5aa4ed7bed3afc7633e5c49
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, t;
  cin >> n >> x;
  while (--n) {
    cin >> t;
    int g = gcd(x, t);
    cout << x / g << '/' << t / g << '\n';
  }
}