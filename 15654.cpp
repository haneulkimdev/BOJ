// http://boj.kr/77b9b35c67b74918903c398e6dac4755
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
  for (int i = 0; i < n; i++) {
    if (!is_used[i]) {
      arr[k] = i;
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