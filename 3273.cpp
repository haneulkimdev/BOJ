// http://boj.kr/4ff08ca3c95a4d85b634efae3365b6ef
#include <bits/stdc++.h>
using namespace std;

int a[100000];
bool occur[2000000];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> x;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (x - a[i] > 0 && occur[x - a[i]]) ans++;
    occur[a[i]] = true;
  }
  cout << ans;
}