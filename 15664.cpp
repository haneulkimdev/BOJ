// http://boj.kr/9b4b37b0396842aa8a21613a4f5d94b0
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
int num[8];

void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++) cout << num[arr[i]] << ' ';
    cout << '\n';
    return;
  }
  int st = 0;
  if (k != 0) st = arr[k - 1] + 1;
  int tmp = 0;
  for (int i = st; i < n; i++) {
    if (tmp != num[i]) {
      arr[k] = i;
      tmp = num[i];
      func(k + 1);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> num[i];
  sort(num, num + n);
  func(0);
}