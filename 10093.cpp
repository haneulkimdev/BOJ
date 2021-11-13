// http://boj.kr/96acf06e5b734010b494a20302ee1adb
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  if (a == b)
    cout << 0 << '\n';
  else
    cout << b - a - 1 << '\n';
  for (long long i = a + 1; i < b; i++) cout << i << ' ';
}