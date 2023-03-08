// http://boj.kr/b1f103ef69ee4011a7a9e1549e845f61
#include <bits/stdc++.h>
using namespace std;

int n, c;
int x[200000];

bool solve(int dist) {
  int cnt = 1;
  int cur = x[0];
  for (int i = 1; i < n; i++) {
    if (x[i] - cur >= dist) {
      cnt++;
      cur = x[i];
    }
  }
  return cnt >= c;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> x[i];
  sort(x, x + n);
  int st = 0;
  int en = 1000000000;
  while (st < en) {
    int mid = (st + en + 1) / 2;
    if (solve(mid))
      st = mid;
    else
      en = mid - 1;
  }
  cout << st;
}