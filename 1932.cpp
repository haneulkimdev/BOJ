// http://boj.kr/58e437f30f3649519bcf144cb854f4a9
#include <bits/stdc++.h>
using namespace std;

int n;
int a[501][501], d[501][501];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> a[i][j];
      d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + a[i][j];
    }
  }
  cout << *max_element(d[n] + 1, d[n] + n + 1);
}