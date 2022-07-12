// http://boj.kr/aae7740ace544c40a8eaea80bd79cf65
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000], d[1000];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    d[i] = a[i];
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) d[i] = max(d[i], d[j] + a[i]);
    }
  }
  cout << *max_element(d, d + n);
}