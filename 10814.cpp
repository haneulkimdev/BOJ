// http://boj.kr/364c8870481c4098aa964f9b867a8545
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
pair<int, string> arr[1000000];
pair<int, string> tmp[1000000];

void merge(int st, int en) {
  int mid = (st + en) / 2;
  int lidx = st;
  int ridx = mid;
  for (int i = st; i < en; i++) {
    if (ridx == en)
      tmp[i] = arr[lidx++];
    else if (lidx == mid)
      tmp[i] = arr[ridx++];
    else if (arr[lidx].X <= arr[ridx].X)
      tmp[i] = arr[lidx++];
    else
      tmp[i] = arr[ridx++];
  }
  for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
  if (en - st == 1) return;
  int mid = (st + en) / 2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st, en);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i].X >> arr[i].Y;
  merge_sort(0, n);
  for (int i = 0; i < n; i++) cout << arr[i].X << ' ' << arr[i].Y << '\n';
}