// http://boj.kr/cd643d9e6eff4ceb83eb97abc9e2346c
#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[1000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  while (m--) {
    sort(a, a + n);
    a[0] = a[1] = a[0] + a[1];
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  cout << sum;
}