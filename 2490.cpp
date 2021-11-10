// http://boj.kr/e8aeb3d536ae4c7db7434fec2bd434d8
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string res = "DCBAE";
  for (int i = 0; i < 3; i++) {
    int cnt = 0;
    for (int j = 0; j < 4; j++) {
      int t;
      cin >> t;
      cnt += t;
    }
    cout << res[cnt] << '\n';
  }
}