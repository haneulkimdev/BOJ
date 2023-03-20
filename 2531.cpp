// http://boj.kr/441dee4be5a84f6c8faa051eb43d4299
#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int a[30000];
int kind[3001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> d >> k >> c;
  for (int i = 0; i < n; i++) cin >> a[i];
  int tot = 0;
  for (int i = 0; i < k; i++) {
    if (kind[a[i]] == 0) tot++;
    kind[a[i]]++;
  }
  int mx = 0;
  int en = k - 1;
  for (int st = 0; st < n; st++) {
    mx = max(mx, tot + (kind[c] == 0));
    en = (en + 1) % n;
    if (kind[a[en]] == 0) tot++;
    kind[a[en]]++;
    if (kind[a[st]] == 1) tot--;
    kind[a[st]]--;
  }
  cout << mx;
}