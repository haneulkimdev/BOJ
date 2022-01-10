// http://boj.kr/93bc0c54aded4cc59d3b114c7348baa3
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
  int st = 1;
  if (k != 0) st = arr[k - 1] + 1;
  for (int i = st; i <= n; i++) {
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