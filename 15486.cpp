// http://boj.kr/34e71b35513549e29ab24b8e03003a73
#include <bits/stdc++.h>
using namespace std;

int n;
int t[1500001], p[1500001], d[1500001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> p[i];
    d[i] = max(d[i], d[i - 1]);
    if (i + t[i] - 1 <= n)
      d[i + t[i] - 1] = max(d[i + t[i] - 1], d[i - 1] + p[i]);
  }
  cout << d[n];
}