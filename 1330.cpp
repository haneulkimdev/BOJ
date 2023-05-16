// http://boj.kr/f90a0d5fae364ccebc2ba4078392dcfb
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a > b)
    cout << ">";
  else if (a < b)
    cout << "<";
  else if (a == b)
    cout << "==";
}