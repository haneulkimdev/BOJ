#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, m;
int arr[1000000];

bool solve(int x) {
  ll cur = 0;
  for (int i = 0; i < n; i++) cur += max(0, arr[i] - x);
  return cur >= m;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
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