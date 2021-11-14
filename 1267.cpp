// http://boj.kr/1c5c09a91823486dbde3690e66837940
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, t;
  cin >> n;
  int y = 0;
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> t;
    y += (t / 30 + 1) * 10;
    m += (t / 60 + 1) * 15;
  }
  if (y < m)
    cout << "Y " << y;
  else if (y > m)
    cout << "M " << m;
  else
    cout << "Y M " << y;
}