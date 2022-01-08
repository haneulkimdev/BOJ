// http://boj.kr/8fe2ca53836c4444abe45ac3ffe33893
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
bool is_used[9];

void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++) cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
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
  func(0);
}