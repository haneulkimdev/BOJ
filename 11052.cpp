// http://boj.kr/80ac0268e0a64c29ad9434a077c4bee0
#include <bits/stdc++.h>
using namespace std;

int n;
int p[1001], d[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    d[i] = p[i];
    for (int j = 1; j < i; j++) d[i] = max(d[i], d[j] + d[i - j]);
  }
  cout << d[n];
}