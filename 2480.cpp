// http://boj.kr/165ba75477c040e392e75de0c8c8dd0e
#include <bits/stdc++.h>
using namespace std;

int a[3];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 3; i++) cin >> a[i];
  sort(a, a + 3);
  if (a[0] == a[2])
    cout << 10000 + a[0] * 1000;
  else if (a[0] == a[1] || a[1] == a[2])
    cout << 1000 + a[1] * 100;
  else
    cout << a[2] * 100;
}