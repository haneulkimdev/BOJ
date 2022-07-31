// http://boj.kr/021f098d3aa6425e944ed7f2bd8b17ef
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001][2], d[100001][2];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i][0];
    for (int i = 1; i <= n; i++) cin >> a[i][1];
    d[1][0] = a[1][0];
    d[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
      d[i][0] = max(d[i - 1][1], d[i - 2][1]) + a[i][0];
      d[i][1] = max(d[i - 1][0], d[i - 2][0]) + a[i][1];
    }
    cout << max(d[n][0], d[n][1]) << '\n';
  }
}