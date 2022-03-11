// http://boj.kr/bba765b6f51c4af89514fa25181ab029
#include <bits/stdc++.h>
using namespace std;

int n;
int s[8], w[8];
int mx = 0;
int cnt = 0;

void func(int k) {
  if (k == n) {
    mx = max(mx, cnt);
    return;
  }
  if (s[k] <= 0 || cnt == n - 1) {
    func(k + 1);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i == k || s[i] <= 0) continue;
    s[k] -= w[i];
    s[i] -= w[k];
    if (s[k] <= 0) cnt++;
    if (s[i] <= 0) cnt++;
    func(k + 1);
    if (s[k] <= 0) cnt--;
    if (s[i] <= 0) cnt--;
    s[k] += w[i];
    s[i] += w[k];
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i] >> w[i];
  func(0);
  cout << mx;
}