// http://boj.kr/1f22f1d4863b401a95784a514f3683a8
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  while (n > 0) {
    n /= 5;
    cnt += n;
  }
  cout << cnt;
}