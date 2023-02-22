// http://boj.kr/376faf7ce16445da8a71d07efb727086
#include <bits/stdc++.h>
using namespace std;

int m, n;
int arr[1000000];

bool solve(int x) {
  int cur = 0;
  for (int i = 0; i < n; i++) cur += arr[i] / x;
  return cur >= m;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
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