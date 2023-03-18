// http://boj.kr/2bc8f1d05591495a9d586cb5815add20
#include <bits/stdc++.h>
using namespace std;

int n, k, mx;
int s[1000000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> s[i];
  int cnt = s[0] % 2;
  int en = 0;
  for (int st = 0; st < n; st++) {
    while (en < n - 1 && cnt + s[en + 1] % 2 <= k) {
      en++;
      cnt += s[en] % 2;
    }
    mx = max(mx, en - st + 1 - cnt);
    cnt -= s[st] % 2;
  }
  cout << mx;
}