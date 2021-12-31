// http://boj.kr/8822b52945064d698d655e9f62cbf81e
#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n) {
  if (n == 1) {
    cout << a << ' ' << b << '\n';
    return;
  }
  func(a, 6 - a - b, n - 1);
  cout << a << ' ' << b << '\n';
  func(6 - a - b, b, n - 1);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << (1 << n) - 1 << '\n';
  func(1, 3, n);
}