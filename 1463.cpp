// http://boj.kr/4c4e3ed108444401ada58063b76f8278
#include <bits/stdc++.h>
using namespace std;

int d[1000001];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    d[i] = d[i - 1] + 1;
    if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
    if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
  }
  cout << d[n];
}