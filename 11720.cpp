// http://boj.kr/b4a131233c3346699f95d267883912e5
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 0; i < n; i++) sum += s[i] - '0';
  cout << sum;
}