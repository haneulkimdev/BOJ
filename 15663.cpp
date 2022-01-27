// http://boj.kr/fabc49cfacd948d6b1aeb0814d64617f
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
bool is_used[8];
int num[8];

void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++) cout << num[arr[i]] << ' ';
    cout << '\n';
    return;
  }
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    if (!is_used[i] && tmp != num[i]) {
      arr[k] = i;
      tmp = num[i];
      is_used[i] = 1;
      func(k + 1);
      is_used[i] = 0;
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