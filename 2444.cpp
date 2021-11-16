// http://boj.kr/670653f967de47138662f135a5a7d1e5
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) cout << ' ';
    for (int j = 0; j < 2 * i - 1; j++) cout << '*';
    cout << '\n';
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < n - i; j++) cout << ' ';
    for (int j = 0; j < 2 * i - 1; j++) cout << '*';
    cout << '\n';
  }
}