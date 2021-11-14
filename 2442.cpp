// http://boj.kr/dd00d6bb475945a08bde1e45b7e9dd65
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n - i; j++) cout << ' ';
    for (int j = 0; j < 2 * i - 1; j++) cout << '*';
    cout << '\n';
  }
}