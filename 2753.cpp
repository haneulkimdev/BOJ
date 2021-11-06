// http://boj.kr/23f0393ecf384386ab520a500517475d
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int year;
  cin >> year;
  if (year % 4 != 0)
    cout << 0;
  else if (year % 100 != 0)
    cout << 1;
  else if (year % 400 != 0)
    cout << 0;
  else
    cout << 1;
}