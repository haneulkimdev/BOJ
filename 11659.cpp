// http://boj.kr/6d906c3e85ec44bcb58efcff26a7e303
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100001], d[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[i] = d[i - 1] + a[i];
  }
  while (m--) {
    int i, j;
    cin >> i >> j;
    cout << d[j] - d[i - 1] << '\n';
  }
}