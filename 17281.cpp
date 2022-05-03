// http://boj.kr/26ccb261c1124a2982d10bcc46594498
#include <bits/stdc++.h>
using namespace std;

int n;
int result[50][9];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 9; j++) cin >> result[i][j];
  int order[9];
  for (int i = 0; i < 9; i++) order[i] = i;
  int ans = 0;
  do {
    if (order[3] != 0) continue;
    int score = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
      bool state[4] = {};
      int cnt = 0;
      while (cnt < 3) {
        int res = result[i][order[idx++]];
        if (idx >= 9) idx = 0;
        state[0] = 1;
        if (res == 0) {
          cnt++;
          continue;
        }
        for (int j = 3; j >= 0; j--) {
          if (!state[j]) continue;
          if (j + res > 3)
            score++;
          else
            state[j + res] = 1;
          state[j] = 0;
        }
      }
    }
    ans = max(ans, score);
  } while (next_permutation(order, order + 9));
  cout << ans;
}