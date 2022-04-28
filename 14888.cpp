// http://boj.kr/6ed606b1173440a3a3da950ad05494fa
#include <bits/stdc++.h>
using namespace std;

int n;
int a[11];
int op[4];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < 4; i++) cin >> op[i];
  vector<int> brute;
  for (int i = 0; i < 4; i++)
    while (op[i]--) brute.push_back(i);
  int mx = 0x80000000;
  int mn = 0x7fffffff;
  do {
    int tmp = a[0];
    for (int i = 0; i < n - 1; i++) {
      if (brute[i] == 0) tmp += a[i + 1];
      if (brute[i] == 1) tmp -= a[i + 1];
      if (brute[i] == 2) tmp *= a[i + 1];
      if (brute[i] == 3) tmp /= a[i + 1];
    }
    mx = max(mx, tmp);
    mn = min(mn, tmp);
  } while (next_permutation(brute.begin(), brute.end()));
  cout << mx << '\n' << mn;
}