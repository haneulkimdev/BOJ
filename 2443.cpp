// http://boj.kr/ec9b095b2cbd4073bcde00c92b27c1db
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < n - i; j++) cout << ' ';
    for (int j = 0; j < 2 * i - 1; j++) cout << '*';
    cout << '\n';
  }
}