// http://boj.kr/ba2bc3e33f904c7e875d7aa8d5179c2d
#include <bits/stdc++.h>
using namespace std;

string gear[4];
int k;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 4; i++) cin >> gear[i];
  cin >> k;
  while (k--) {
    int a, b;
    cin >> a >> b;
    a--;
    int dir[4] = {};
    dir[a] = b;
    int idx = a;
    while (idx > 0 && gear[idx][6] != gear[idx - 1][2]) {
      dir[idx - 1] = -dir[idx];
      idx--;
    }
    idx = a;
    while (idx < 3 && gear[idx][2] != gear[idx + 1][6]) {
      dir[idx + 1] = -dir[idx];
      idx++;
    }
    for (int i = 0; i < 4; i++) {
      if (dir[i] == 1)
        rotate(gear[i].rbegin(), gear[i].rbegin() + 1, gear[i].rend());
      else if (dir[i] == -1)
        rotate(gear[i].begin(), gear[i].begin() + 1, gear[i].end());
    }
  }
  int ans = 0;
  for (int i = 0; i < 4; i++)
    if (gear[i][0] == '1') ans += 1 << i;
  cout << ans;
}