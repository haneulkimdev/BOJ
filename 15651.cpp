// http://boj.kr/1fa5517b8697424e9568a246a94dc9e8
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[7];

void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++) cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    arr[k] = i;
    func(k + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}