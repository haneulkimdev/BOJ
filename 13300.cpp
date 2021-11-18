// http://boj.kr/0f82101e4ba645e08c2980b052a00186
#include <bits/stdc++.h>
using namespace std;

int freq[2][6];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  while (n--) {
    int s, y;
    cin >> s >> y;
    freq[s][y - 1]++;
  }
  int ans = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 6; j++) ans += (freq[i][j] + k - 1) / k;
  cout << ans;
}