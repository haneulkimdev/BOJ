// http://boj.kr/a1676818654d482ba858370cc998e5c2
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001], d[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[i] = max(a[i], d[i - 1] + a[i]);
  }
  cout << *max_element(d + 1, d + n + 1);
}