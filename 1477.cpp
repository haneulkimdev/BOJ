// http://boj.kr/f88fcf6f28684bc8882bdf815ae0b848
#include <bits/stdc++.h>
using namespace std;

int n, m, l;
int a[52];

bool solve(int x) {
  int cur = 0;
  for (int i = 0; i <= n; i++) cur += (a[i + 1] - a[i] - 1) / x;
  return cur > m;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> l;
  a[0] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[n + 1] = l;
  sort(a, a + n + 1);
  int st = 1;
  int en = l;
  while (st < en) {
    int mid = (st + en) / 2;
    if (solve(mid))
      st = mid + 1;
    else
      en = mid;
  }
  cout << st;
}