// http://boj.kr/966a732b49c742dda7a792a74281c5ee
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  while (true) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0) break;
    cout << "Case " << tc++ << ": " << c / b * a + min(c % b, a) << '\n';
  }
}