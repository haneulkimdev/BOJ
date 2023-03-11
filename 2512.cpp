// http://boj.kr/f7bcc3ca5414489490a8b6a0e0fe6585
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10000];

bool solve(int x) {
  int cur = 0;
  for (int i = 0; i < n; i++) cur += min(a[i], x);
  return cur <= m;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  int st = 1;
  int en = *max_element(a, a + n);
  while (st < en) {
    int mid = (st + en + 1) / 2;
    if (solve(mid))
      st = mid;
    else
      en = mid - 1;
  }
  cout << st;
}