// http://boj.kr/c6bbb64ff4e94fa982acca90dc2ad08d
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, t;
  cin >> n >> x;
  while (n--) {
    cin >> t;
    if (t < x) cout << t << ' ';
  }
}