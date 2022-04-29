// http://boj.kr/cf8797ec979d47468ae0293d82b606b7
#include <bits/stdc++.h>
using namespace std;

int n;
int s[20][20];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> s[i][j];
  vector<bool> team(n);
  fill(team.begin() + n / 2, team.end(), 1);
  int ans = 0x7fffffff;
  do {
    int diff = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (team[i] != team[j]) continue;
        if (team[i] == 0)
          diff += s[i][j] + s[j][i];
        else
          diff -= s[i][j] + s[j][i];
      }
    }
    ans = min(ans, abs(diff));
  } while (next_permutation(team.begin(), team.end()));
  cout << ans;
}