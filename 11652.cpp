// http://boj.kr/39b218afb0ad411c8919d24746785895
#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int cnt = 1;
  int mxcnt = 1;
  long long mxval = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i - 1] == a[i])
      cnt++;
    else
      cnt = 1;
    if (cnt > mxcnt) {
      mxcnt = cnt;
      mxval = a[i];
    }
  }
  cout << mxval;
}