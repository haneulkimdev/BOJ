// http://boj.kr/acd181302ce74c6b968cfbfb85c1468f
#include <bits/stdc++.h>
using namespace std;

int s[301];
int n;
int d[301];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  d[1] = s[1];
  if (n > 1) d[2] = s[1] + s[2];
  if (n > 2) d[3] = max(s[1], s[2]) + s[3];
  for (int i = 4; i <= n; i++) d[i] = max(d[i - 2], d[i - 3] + s[i - 1]) + s[i];
  cout << d[n];
}