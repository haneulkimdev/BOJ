// http://boj.kr/17d1ec791b564f3c934467f0371c0e63
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  n--;
  int cnt = 0;
  while ((n -= 6 * cnt) > 0) cnt++;
  cout << cnt + 1;
}