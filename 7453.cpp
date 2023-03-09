// http://boj.kr/d71c17f6218b4bd2b15a20457922cfc0
#include <bits/stdc++.h>
using namespace std;

int n;
int a[4000], b[4000], c[4000], d[4000];
vector<int> two;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) two.push_back(a[i] + b[j]);
  }
  sort(two.begin(), two.end());
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cnt += upper_bound(two.begin(), two.end(), -(c[i] + d[j])) -
             lower_bound(two.begin(), two.end(), -(c[i] + d[j]));
  }
  cout << cnt;
}
