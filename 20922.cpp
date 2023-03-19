// http://boj.kr/c45b0ef864c345f3afe3bcb88b985e81
#include <bits/stdc++.h>
using namespace std;

int n, k, mx;
int a[200000];
int cnt[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  cnt[a[0]]++;
  int en = 0;
  for (int st = 0; st < n; st++) {
    while (en < n - 1 && cnt[a[en + 1]] < k) {
      en++;
      cnt[a[en]]++;
    }
    mx = max(mx, en - st + 1);
    cnt[a[st]]--;
  }
  cout << mx;
}