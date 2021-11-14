// http://boj.kr/5e2bb7122b9945e6ad513d610fdd0d6d
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) cout << ' ';
    for (int j = 0; j <= i; j++) cout << '*';
    cout << '\n';
  }
}