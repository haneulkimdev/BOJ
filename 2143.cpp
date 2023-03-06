// http://boj.kr/ef0aacfe869e46bf9a172dcb4d76c4a2
#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[1001], b[1001];
vector<int> v1, v2;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    for (int j = 1; j <= i; j++) v1.push_back(a[i] - a[j - 1]);
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    b[i] += b[i - 1];
    for (int j = 1; j <= i; j++) v2.push_back(b[i] - b[j - 1]);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  long long cnt = 0;
  for (int i : v1)
    cnt += upper_bound(v2.begin(), v2.end(), t - i) -
           lower_bound(v2.begin(), v2.end(), t - i);
  cout << cnt;
}