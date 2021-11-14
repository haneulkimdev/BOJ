// http://boj.kr/802d86a85d00443bae78c7d4dedbc01a
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) cout << '*';
    cout << '\n';
  }
}