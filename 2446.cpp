// http://boj.kr/d2d93fa4da604389b0998370edcca4d2
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i - 1; j++) cout << ' ';
    for (int j = 0; j < 2 * (n - i) + 1; j++) cout << '*';
    cout << '\n';
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < i - 1; j++) cout << ' ';
    for (int j = 0; j < 2 * (n - i) + 1; j++) cout << '*';
    cout << '\n';
  }
}