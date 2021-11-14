// http://boj.kr/745b95a76db24a2e918bf909ff3f3bd2
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) cout << '*';
    cout << '\n';
  }
}